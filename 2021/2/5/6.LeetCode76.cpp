/*************************************************************************
	> File Name: 6.LeetCode76.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月05日 星期五 23时14分24秒
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

// WA

string minWindow(string s, string t) {
    vector<int> nums(26, 0), cnt(26, 0), check(26, 0);
    int len_t = t.size();
    for (char &c : t) nums[c - 'A']++, cnt[c - 'A']++, check[c - 'A'] = 1;
    int l = 0, r = 0, num = len_t, len = INT32_MAX;
    string ans = "";
    while (s[r]) {
        if (check[s[r] - 'A'] && cnt[s[r] - 'A']) cnt[s[r] - 'A']--, num--;
        if (num) {
            r++;
            continue;
        }
        while (!num) {
            if (check[s[l] - 'A'] && cnt[s[l] - 'A'] < nums[s[l] - 'A']) cnt[s[l] - 'A']++, num++;
            l++;
        }
        if (len > r - l + 2) {
            ans = s.substr(l - 1, r - l + 2);
            len = r - l + 2;
        }
        r++;
    }
    if (!num) {
        while (!num) {
            if (check[s[l] - 'A'] && cnt[s[l] - 'A'] < nums[s[l] - 'A']) cnt[s[l] - 'A']++, num++;
            l++;
        }
        if (len > r - l + 1) {
            ans = s.substr(l - 1, r - l + 1);
            len = r - l + 1;
        }
    }
    return ans;
}

int main() {
    return 0;
}
