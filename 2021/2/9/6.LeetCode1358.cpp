/*************************************************************************
	> File Name: 6.LeetCode1358.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月09日 星期二 10时03分55秒
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

int numberofKSubstrings(string &s, int k) {
    int n = s.size(), l = 0, r = 0, ans = 0, num = 0;
    vector<int> cnt(3, 0);
    while (r < n) {
        if (!cnt[s[r] - 'a']) num++;
        cnt[s[r] - 'a']++;
        while (num > k) {
            if (!(--cnt[s[l++] - 'a'])) num--;
        }
        ans += r - l + 1;
        r++;
    }
    return ans;
}

int numberOfSubstrings(string s) {
    return numberofKSubstrings(s, 3) - numberofKSubstrings(s, 2);
}

int main() {
    return 0;
}
