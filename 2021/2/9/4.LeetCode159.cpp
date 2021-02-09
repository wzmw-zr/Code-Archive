/*************************************************************************
	> File Name: 4.LeetCode159.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月09日 星期二 09时27分02秒
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

int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size(), l = 0, r = 0, ans = 0, num = 0;
    vector<int> cnt(256, 0);
    while (r < n) {
        if (!cnt[s[r]]) num++;
        cnt[s[r]]++;
        if (num > 2) {
            ans = max(ans, r - l);
            while (num > 2) {
                if (!(--cnt[s[l++]])) num--;
            }
        }
        r++;
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    return 0;
}
