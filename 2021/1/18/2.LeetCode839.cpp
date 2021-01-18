/*************************************************************************
	> File Name: 2.LeetCode839.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月18日 星期一 20时26分30秒
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

int dfs(string s, unordered_map<string, bool> &mp) {
    if (mp.count(s) == 0) return 0;
    if (mp[s]) return 0;
    int n = s.size();
    mp[s] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            swap(s[i], s[j]);
            if (mp.count(s) && !mp[s]) dfs(s, mp);
            swap(s[i], s[j]);
        }
    }
    return 1;
}

int numSimilarGroups(vector<string>& strs) {
    unordered_map<string, bool> mp;
    for (auto &s : strs) mp[s] = false;
    int ans = 0;
    for (auto &s : strs) {
        ans += dfs(s, mp);
    }
    return ans;
}

int main() {
    return 0;
}
