/*************************************************************************
	> File Name: 5.LeetCode340.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月09日 星期二 09时47分08秒
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

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.size(), l = 0, r = 0, ans = 0, num = 0;
    vector<int> cnt(256, 0);
    while (r < n) {
        if (!cnt[s[r]]) num++;
        cnt[s[r]]++;
        if (num > k) {
            ans = max(ans, r - l);
            while (num > k) {
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
