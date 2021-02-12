/*************************************************************************
	> File Name: 4.LeetCode1456.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月13日 星期六 00时24分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int check(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

int maxVowels(string s, int k) {
    int l = 0, r = 0, cnt = 0, ans = 0;
    while (r < k - 1) cnt += check(s[r++]);
    while (s[r]) {
        cnt += check(s[r++]);
        ans = max(cnt, ans);
        cnt -= check(s[l++]);
    }
    return ans;
}

int main() {
    return 0;
}
