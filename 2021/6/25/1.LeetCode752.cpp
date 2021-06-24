/*************************************************************************
	> File Name: 1.LeetCode752.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月25日 星期五 00时21分42秒
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

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> st;
    unordered_map<string, int> mp;
    queue<string> que;
    for (auto &s : deadends) st.insert(s);
    if (!st.count("0000")) {
        mp["0000"] = 0;
        que.push("0000");
    }
    while (!que.empty()) {
        string s = que.front();
        que.pop();
        if (s == target) return mp[target];
        int cnt = mp[s];
        for (int i = 0; i < 4; i++) {
            string temp = s;
            int t = temp[i] - '0';
            int x1 = (t + 1) % 10;
            int x2 = (t + 9) % 10;
            temp[i] = x1 + '0';
            if (!mp.count(temp) && !st.count(temp)) {
                mp[temp] = cnt + 1;
                que.push(temp);
            }
            temp[i] = x2 + '0';
            if (!mp.count(temp) && !st.count(temp)) {
                mp[temp] = cnt + 1;
                que.push(temp);
            }
        }
    }
    return -1;
}

int main() {
    return 0;
}
