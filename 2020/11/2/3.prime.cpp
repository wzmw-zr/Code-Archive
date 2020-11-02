/*************************************************************************
	> File Name: 3.prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月02日 星期一 14时56分40秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

int is_prime[MAX_N + 10];

void init() {
    for (int i = 0; i <= MAX_N; i++) is_prime[i] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        for (int j = 2; i * j <= MAX_N; j++) {
            is_prime[i * j] = 0;
        }
    }
}

int get_cnt(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) cnt += is_prime[i];
    return cnt;
}

int main() {
    init();
    int n;
    cin >> n;
    cout << get_cnt(n) << endl;
    return 0;
}
