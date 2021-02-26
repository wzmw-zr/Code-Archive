/*************************************************************************
	> File Name: 1.LeetCode395.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月27日 星期六 00时02分27秒
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

bool check(string &s, int x, int y, int k) {
    vector<int> cnt(26, 0);
    for (int i = x; i <= y; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (!cnt[i]) continue;
        if (cnt[i] >= k) continue;
        return false;
    }
    return true;
}

// TLE

int longestSubstring(string s, int k) {
    int n = s.size(), ans = 0;
    for (int len = n; len >= 1; len--) {
        for (int i = 0; i + len - 1 < n; i++) {
            if (!check(s, i, i + len - 1, k)) continue;
            ans = len;
            break;
        }
    }
    return ans;
}

int main() {
    return 0;
}
