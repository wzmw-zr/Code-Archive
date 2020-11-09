/*************************************************************************
	> File Name: 3.EP29.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月30日 星期一 21时59分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
using namespace std;

typedef struct {
    int num, times;
} intnode;

typedef struct {
    int p_num;
    intnode p[10];
} bigint;

bigint num[max_n * max_n];
int prime[max_n + 5] = {0};
int num_len = 0;

void init() {
    memset(num, 0, sizeof(num));
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void get_val(int a, int b) {
    int x = a;
    for (int i = 1; i <= prime[0]; i++) {
        if (x == 1) break;
        int number = 0;
        while (x % prime[i] == 0) {
            x /= prime[i];
            number++;
        } 
        if (!num) continue;
        int index = num[num_len].p_num;
        num[num_len].p[index].num = prime[i];
        num[num_len].p[index].times = number;
        num[num_len].p_num += 1;
    }
}

int cmp(const void *a, const void *b) {
    return memcmp(a, b, sizeof(bigint));
}

int main() {
    init();
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            get_val(i, j);
            num_len++;
        }
    }
    qsort(num, num_len, sizeof(bigint), cmp);
    int total = 0;
    for (int i = 1; i <= num_len; i++) {
        if (memcmp(&num[i], &num[i + 1], sizeof(bigint)) == 0) continue;
        total++;
    }
    cout << total << endl;
    return 0;
}
