/*************************************************************************
	> File Name: 5.LeetCode5620.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月06日 星期日 10时46分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long to_digit(int n) {
    string s = "";
    while (n) {
        s += '0' + (n & 1);
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return stol(s);
}

int concatenatedBinary(int n) {
    long ans = 1;
    long MOD = 1e9 + 7;
    for (int i = n; i >= 1; i--) {
        ans *= to_digit(i);
        ans %= MOD;
    }
    return (int) ans;
}

int main() {
    int n;
    cin >> n;
    cout << concatenatedBinary(n) << endl;
    return 0;
}
