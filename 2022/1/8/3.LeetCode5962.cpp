/*************************************************************************
	> File Name: 3.LeetCode5962.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月08日 星期六 22时40分02秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> mp;
    for (auto word : words) mp[word]++;
    unordered_map<string, int> diff_digits;
    unordered_map<string, int> same_digits;
    for (auto &&[word, cnt] : mp) {
        if (word[0] == word[1]) {
            same_digits[word] = cnt;
        } else {
            string temp = word;
            reverse(temp.begin(), temp.end());
            if (mp.count(temp)) diff_digits[word] = min(mp[word], mp[temp]);
        }
    }
    int same = 0, diff = 0, odd = 0;
    for (auto &&[word, cnt] : diff_digits) diff += cnt;
    for (auto &&[word, cnt] : same_digits) {
        same += (cnt & 1) ? cnt - 1 : cnt;
        odd += (cnt & 1) ? 1 : 0;
    }
    int ans = 2 * (same + diff + (odd ? 1 : 0));
    return ans;
}

int main() {
    return 0;
}
