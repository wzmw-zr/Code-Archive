/*************************************************************************
	> File Name: 1.LeetCode168.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月29日 星期二 00时04分37秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string convertToTitle(int columnNumber) {
    string ans = "";
    while (columnNumber) {
        int t = columnNumber % 26;
        t = (t + 25) % 26;
        columnNumber = (columnNumber - 1) / 26;
        ans += 'A' + t;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int columnNumber;
    cin >> columnNumber;
    cout << convertToTitle(columnNumber) << endl;
    return 0;
}
