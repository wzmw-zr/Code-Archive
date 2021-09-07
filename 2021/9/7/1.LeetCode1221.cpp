/*************************************************************************
	> File Name: 1.LeetCode1221.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月07日 星期二 08时07分48秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int balancedStringSplit(string s) {
    int l = 0, r = 0, ans = 0;
    for (char c : s) {
        if (c == 'L') l++;
        else r++;
        if (l == r) ans++, l = r = 0;
    }
    return ans;
}


int main() {
    string s;
    cin >> s;
    cout << balancedStringSplit(s) << endl;
    return 0;
}
