/*************************************************************************
	> File Name: 1.LeetCode76.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月10日 星期三 09时01分44秒
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

bool check(unordered_map<char, int> &mp, unordered_map<char, int> &cnt) {
    for (char c = 'a'; c <= 'z'; c++) 
        if (cnt[c] < mp[c]) return false;
    for (char c = 'A'; c <= 'Z'; c++) 
        if (cnt[c] < mp[c]) return false;
    return true;
}

string minWindow(string s, string t) {
    unordered_map<char, int> mp, cnt;
    for (char c = 'a'; c <= 'z'; c++) mp[c] = 0, cnt[c] = 0;
    for (char c = 'A'; c <= 'Z'; c++) mp[c] = 0, cnt[c] = 0;
    for (int i = 0; t[i]; i++) mp[t[i]]++;
    int l = 0, r = 0, ans = INT32_MAX, ind = -1;
    while (s[r]) {
        cnt[s[r]]++;
        while (check(mp, cnt)) {
            if (r - l + 1 < ans) ans = r - l + 1, ind = l;
            cnt[s[l++]]--;
        }
        r++;
    }
    if (ind == -1) return "";
    return s.substr(ind, ans);
}

int main() {
    return 0;
}
