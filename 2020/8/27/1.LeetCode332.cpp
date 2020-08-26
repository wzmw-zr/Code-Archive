/*************************************************************************
	> File Name: 1.LeetCode332.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月27日 星期四 00时23分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    map<string, vector<string>> mp;
    set<string> st;
    for (auto &x : tickets) {
        if (mp.find(x[0]) == mp.end()) mp[x[0]] = vector<string>(0, "");
        mp[x[0]].push_back(x[1]);
        st.insert(x[0]);
    }
    for (auto x : st) {
        sort(mp[x].begin(), mp[x].end(), [](string a, string b) { return a < b; });
    }
    //cout << mp.size() << endl;
    string str = "JFK";
    cout << str << endl;
    while (1) {
        cout << str << endl;
        ans.push_back(str);
        string temp = str;
        if (mp.find(temp) == mp.end()) break;
        str = mp[str][0];
        if (mp[temp].size() == 0) break;
        mp[temp].erase(mp[temp].begin());
    }
    cout << endl;
    return ans;
}

int main() {
    int n;
    vector<vector<string>> tickets;
    string from, to;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        tickets.push_back({from, to});
    }
    for (auto x : tickets) cout << x[0] << " " << x[1] << endl;
    vector<string> ans = findItinerary(tickets);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
