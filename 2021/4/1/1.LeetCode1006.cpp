/*************************************************************************
	> File Name: 1.LeetCode1006.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月01日 星期四 00时04分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int clumsy(int N) {
    if (N == 1) return 1;
    if (N == 2) return 2;
    if (N == 3) return 6;
    int ans = 0;
    ans += N * (N - 1) / (N - 2) + N - 3;
    N -= 4;
    while (N >= 4) {
        ans -= N * (N - 1) / (N - 2);
        ans += N - 3;
        N -= 4;
    }
    if (N == 1) return ans - 1;
    if (N == 2) return ans - 2;
    if (N == 3) return ans - 6;
    return ans;
}

int main() {
    int N;
    cin >> N;
    cout << clumsy(N) << endl;
    return 0;
}
