/*************************************************************************
	> File Name: 2.1007.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月27日 星期日 09时39分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100010

int t, n, m;
int v[MAX_N + 5], prime[MAX_N + 5];

void primes() {
    v[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (v[i] == 0) {
            v[i] = i;
            for (int j = 2; i * j <= MAX_N; j++) {
                v[i * j] = i;
            }
        }
    }
}


int main() {
    primes();
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int temp = n;
        n /= v[n];
        if (n == 1) {
            printf("0\n");   
            continue;
        }
        n /= v[n];
        if (n == 1)  printf("-1\n");
        else printf("%d\n", temp / n);
    }
    return 0;
}
