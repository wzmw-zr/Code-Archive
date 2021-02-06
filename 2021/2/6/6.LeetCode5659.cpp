/*************************************************************************
	> File Name: 6.LeetCode5659.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 22时38分40秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minimumLength(string s) {
    int n = s.size(), l = 0, r = n - 1;
    while (l < r && s[l] == s[r]) {
        while (s[l + 1]) {
            l++;
            if (s[l] != s[l - 1]) break;
        }
        while (r) {
            r--;
            if (s[r] != s[r + 1]) break;
        }
    }
    if (l <= r) return r - l + 1;
    return 0;
}

int main() {
    return 0;
}
