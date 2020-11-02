/*************************************************************************
	> File Name: 4.prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月02日 星期一 15时16分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

int is_prime[MAX_N + 10];
int prime[MAX_N + 10];
int cnt;

void init() {
    for (int i = 2; i <= MAX_N; i++) is_prime[i] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) prime[++cnt] = i;
        for (int j = 1; (j <= cnt) && (i * prime[j] <= MAX_N); j++) {
            is_prime[i * prime[j]] = 0;
            if (!(i % prime[j])) break;
        }
    }
}

int get_cnt(int n) {
    int cnt = 0;
    for (int i = 0; i <= n; i++) cnt += is_prime[i];
    return cnt;
}

int main() {
    init();
    int n;
    cin >> n;
    cout << get_cnt(n) << endl;
    return 0;
}
