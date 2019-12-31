/*************************************************************************
	> File Name: 9.prime.distance.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 20时12分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define max_n 8000000
using namespace std;

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve(int l, int r) {
    int min, max = 0, i;
    int min_l, min_r,max_l, max_r;
    for (i = 2; i < prime[0]; i++) {
        if (prime[i] < l) continue;
        break;
    }
    if (prime[i + 1] > r) {
        printf("There are no adjacent primes.\n");
        return;
    }
    min = prime[i + 1] - prime[i];
    min_l = prime[i], min_r = prime[i + 1];
    for (; i <= prime[0] && prime[i + 1] <= r; i++) {
        if (prime[i + 1] - prime[i] > max) {
            max = prime[i + 1] - prime[i];
            max_l = prime[i];
            max_r = prime[i + 1];
        }
        if (prime[i + 1] - prime[i] < min){
            min_l = prime[i];
            min_r = prime[i + 1];
            min = prime[i + 1] - prime[i];
        }
    }
    printf("%d,%d are closest, %d,%d are most distant.\n", min_l, min_r, max_l, max_r);
}

int main() {
    init();
    int l, r;
    scanf("%d%d", &l, &r);
    solve(l, r);
    return 0;
}
