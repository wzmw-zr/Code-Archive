/*************************************************************************
	> File Name: 1.HZOJ521.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月12日 星期四 13时31分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define MAX_N 3000000

int n, r, number[35], num[MAX_N + 5], prime[MAX_N + 5];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!num[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            num[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int prime_cnt(int *number, int n, int r, int s, int sum) {
    if (s == n + 1 && r) return 0; 
    if (!r && !num[sum]) return 1;
    if (!r && num[sum]) return 0;
    int ret = 0;
    for (int i = s; i <= n; i++) {
        ret += prime_cnt(number, n, r - 1, i + 1, sum + number[i]);
    }
    return ret;
}

int main() {
    init();
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> number[i];
    cout << prime_cnt(number, n, r, 1, 0) << endl;
    return 0;
}
