/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月18日 星期三 19时01分17秒
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
using namespace std;

vector<int> cnts = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
  int month;
  int day;

  Date() = default;
  Date(string &date) : month(stoi(date.substr(5, 2))), day(stoi(date.substr(8, 2))) {}

  bool operator<(const struct Date &that) const {
    return this->month == that.month ? this->day < that.day : this->month < that.month;
  }

  int operator-(const struct Date &that) const {
    if (*this < that)
      return (that - *this) * -1;
    if (this->month == that.month)
      return this->day - that.day;
    int ans = 0;
    for (int i = that.month + 1; i < this->month; i++)
      ans += cnts[i];
    ans += cnts[that.month] - that.day;
    ans += this->day;
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  getchar();
  unordered_map<string, vector<Date>> mp;
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    string date;
    int ind = 0;
    while (line[ind] && line[ind] != ' ')
      date += line[ind++];
    if (line[ind])
      ind++;
    Date d(date);

    while (line[ind]) {
      string s;
      while (line[ind] && line[ind] != ' ')
        s += line[ind++];
      if (line[ind])
        ind++;
      if (!mp.count(s))
        mp[s] = vector<Date>();
      mp[s].push_back(date);
    }
  }
  string line;
  getline(cin, line);
  int ind = 0;
  string date;
  while (line[ind] && line[ind] != ' ')
    date += line[ind++];
  if (line[ind])
    ind++;
  Date d(date);
  string phone = line.substr(ind);
  int ans = 0, sum = 0;
  if (mp.count(phone)) {
    for (auto && x : mp[phone]) {
      int diff = d - x;
      ans += diff >= 0;
      sum += (diff > 3) ? diff - 3 : 0;
    }
  }
  cout << ans << " " << sum << endl;
  return 0;
}
