/*************************************************************************
	> File Name: 1.LeetCode633.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月28日 星期三 00时04分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

bool judgeSquareSum(int c) {
    int x = 0, y = sqrt(c / 2) + 1;
    while (x <= y) {
        int r = c - x * x;
        if (r < 0) break;
        int t = sqrt(r);
        if (r == t * t) return true;
        x++;
    }
    return false;
}

int main() {
    int c;
    cin >> c;
    cout << (judgeSquareSum(c) ? "True" : "False") << endl;
    return 0;
}
