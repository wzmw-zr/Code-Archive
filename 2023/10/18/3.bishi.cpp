/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月18日 星期三 20时27分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <functional>
using namespace std;

struct IP_CIDR {
  int mask;
  int ip;

  IP_CIDR() = default;
  IP_CIDR(string &s) : mask(0xffffffff) {
    vector<int> vals;
    int ind = 0;
    while (s[ind] && s[ind] != '/') {
      string t;
      while (s[ind] && s[ind] != '/' && s[ind] != '.')
        t += s[ind++];
      vals.push_back(stoi(t));
      if (s[ind] && s[ind] == '.')
        ind++;
    }
    if (s[ind]) {
      int mask_len = stoi(s.substr(ind + 1));
      mask = 0;
      for (int i = 0; i < mask_len; i++)
        mask |= (1 << (31 - i));
    }
    ip = 0;
    reverse(vals.begin(), vals.end());
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 8; j++) {
        ip |= ((vals[i] >> j) & 1) << (i * 8 + j);
      }
    }
  }

  bool match(const IP_CIDR &x) {
    return (this->ip & this->mask) == (x.ip & this->mask);
  }
};

struct Rule {
  IP_CIDR ip_or_cidr;
  char action; 
  string chain_name_2;

  Rule() = default;
  Rule(string &ip_or_cidr, char action) : ip_or_cidr(ip_or_cidr), action(action) {}
  Rule(string &ip_or_cidr, char action, string &chain_name_2) : ip_or_cidr(ip_or_cidr), action(action), chain_name_2(chain_name_2) {}

  bool match(IP_CIDR &x) {
    return this->ip_or_cidr.match(x);
  }
};


int main() {
  int n;
  cin >> n;
  char op;
  string chain_name;
  string ip_or_cidr;
  char action;
  string chain_name_2;

  unordered_map<string, list<Rule>> mp;

  function<char(string &, IP_CIDR &)> dfs = [&](string &chain_name, IP_CIDR &target) {
    if (!mp.count(chain_name))
      return 'U';
    for (auto && x : mp[chain_name]) {
      if (x.action == 'G') {
        char t = dfs(x.chain_name_2, target);
        if (t != 'U')
          return t;
      }
      if (x.ip_or_cidr.match(target))
        return x.action;
    }
    return 'U';
  };

  for (int i = 0; i < n; i++) {
    cin >> op;
    switch (op) {
      case 'I': {
        cin >> chain_name >> ip_or_cidr >> action;
        if (!mp.count(chain_name))
          mp[chain_name] = list<Rule>();
        mp[chain_name].push_front(Rule(ip_or_cidr, action));
      } break;
      case 'A': {
        cin >> chain_name >> ip_or_cidr >> action;
        if (!mp.count(chain_name))
          mp[chain_name] = list<Rule>();
        mp[chain_name].push_back(Rule(ip_or_cidr, action));
      } break;
      case 'D': {
        cin >> chain_name >> ip_or_cidr >> action;
        if (mp.count(chain_name)) {
          for (auto iter = mp[chain_name].begin(); iter != mp[chain_name].end(); ) {
            if ((*iter).ip_or_cidr.match(IP_CIDR(ip_or_cidr)) && (*iter).action == action)
              iter = mp[chain_name].erase(iter);
            else
              iter++;
          }
        }
      } break;
      case 'G': {
        cin >> chain_name >> ip_or_cidr >> action >> chain_name_2;
        if (!mp.count(chain_name))
          mp[chain_name] = list<Rule>();
        if (!mp.count(chain_name_2))
          mp[chain_name_2] = list<Rule>();
        mp[chain_name].push_front(Rule(ip_or_cidr, action, chain_name_2));
      } break;
      case 'M': {
        string ip;
        cin >> ip;
        IP_CIDR ip_t(ip);
        string chain_name = "c0";
        cout << dfs(chain_name, ip_t) << endl;
      } break;
    }
  }
  return 0;
}
