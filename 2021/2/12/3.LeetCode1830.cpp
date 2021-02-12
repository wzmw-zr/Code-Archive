/*************************************************************************
	> File Name: 3.LeetCode1830.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月12日 星期五 08时53分27秒
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

int lengthOfLongestSubstring(string s) {
    vector<int> cnt(256, 0);
    int l = 0, r = 0, ans = 0;
    while (s[r]) {
        cnt[s[r]]++;
        if (cnt[s[r]] > 1) {
            ans = max(ans, r - l);
            while (l <= r && cnt[s[r]] > 1) cnt[s[l++]]--;
        }
        r++;
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    return 0;
}
