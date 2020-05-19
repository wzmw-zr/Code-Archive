/*************************************************************************
	> File Name: 0.LeetCode680.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月19日 星期二 17时59分48秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s, int ind) {
    s.replace(ind, 1, "");
    cout << s << endl;
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] == s[r]) l++, r--;
        else return false;
    }
    return true;
}

bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] == s[r]) l++, r--;
        else {
            return isPalindrome(s, l) || isPalindrome(s, r);
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (validPalindrome(s) ? "Yes" : "False") << endl;
    return 0;
}
