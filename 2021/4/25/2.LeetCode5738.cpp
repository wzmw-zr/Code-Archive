/*************************************************************************
	> File Name: 2.LeetCode5738.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月25日 星期日 10时30分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int sumBase(int n, int k) {
    vector<int> base(10, 1);
    for (int i = 1; i < 10; i++) base[i] = base[i - 1] * k;
    int ans = 0;
    while (n) {
        for (int i = 9; i >= 0; i--) {
            if (n >= base[i]) {
                int m = n / base[i];
                n %= base[i];
                ans = ans * 10 + m;
            }
            else ans *= 10;
        }
    }
    int sum = 0;
    while (ans) {
        sum += ans % 10;
        ans /= 10;
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << sumBase(n, k) << endl;
    return 0;
}
