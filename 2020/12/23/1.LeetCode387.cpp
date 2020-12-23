/*************************************************************************
	> File Name: 1.LeetCode387.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月23日 星期三 09时31分50秒
 ************************************************************************/

#include<iostream>
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

int firstUniqChar(string s) {
    unordered_map<char, vector<int>> mp;
    for (int i = 0; s[i]; i++) {
        if (!mp.count(s[i])) mp[s[i]] = {};
        mp[s[i]].push_back(i);
    }
    int ans = INT32_MAX;
    for (auto &&[c, pos] : mp) {
        if (pos.size() > 1) continue;
        ans = min(ans, pos[0]);
    }
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
    return 0;
}
