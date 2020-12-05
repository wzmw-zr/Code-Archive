/*************************************************************************
	> File Name: 2.LeetCode1152.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月06日 星期日 07时06分25秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct Action {
    int timestamp;
    string website;
    Action() = default;
    Action(int timestamp, string website) : timestamp(timestamp), website(website) {} 
    bool operator<(const struct Action &a) const {
        return this->timestamp < a.timestamp;
    }
};

struct User {
    string name;
    vector<Action> action;
    set<string> path;
    User() = default;
    User(string name, vector<Action> action) : name(name), action(action) {}
};

void handle(vector<User> &users) {
    int n = users.size();
    for (int i = 0; i < n; i++) {
        int m = users[i].action.size();
        for (int j = 0; j < m - 2; j++) {
            for (int k = j + 1; k < m - 1; k++) {
                for (int t = k + 1; t < m; t++) {
                    users[i].path.insert(users[i].action[j].website + " " + users[i].action[k].website + " " + users[i].action[t].website);
                }
            }
        }
    }
}

vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    int n = username.size();
    unordered_map<string, vector<Action>> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(username[i])) mp[username[i]] = vector<Action>(0);
        mp[username[i]].push_back({timestamp[i], website[i]});
    }
    for (auto &x : mp) sort(x.second.begin(), x.second.end());
    vector<User> users;
    for (auto &x : mp) users.push_back({x.first, x.second});
    handle(users);
    unordered_map<string, int> cnt;
    for (int i = 0; i < users.size(); i++) {
        for (auto x : users[i].path) cnt[x]++;
    }
    int mmax = 0;
    for (auto &x : cnt) mmax = max(mmax, x.second);
    vector<string> ans;
    for (auto &x : cnt) {
        if (x.second == mmax) ans.push_back(x.first);
    }
    sort(ans.begin(), ans.end());
    string str;
    istringstream s(ans[0]);
    vector<string> res;
    while (s >> str) res.push_back(str);
    return res;
}

int main() {
    return 0;
}
