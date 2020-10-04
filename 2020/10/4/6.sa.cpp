/*************************************************************************
	> File Name: 6.sa.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 14时12分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define MAX_N 100010
char s[MAX_N + 10];
int sa[MAX_N + 10], rk[MAX_N << 1 + 10], old_rk[MAX_N << 1 + 10];
int n, w;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
    //printf("n = %d\n", n);
    //for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
    //printf("\n");
    for (w = 1; w < n; w <<= 1) {
        sort(sa + 1, sa + n, [](int a, int b) {return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b]; });
        memcpy(old_rk, rk, sizeof(rk));
        for (int i = 1, p = 0; i <= n; i++) {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] && old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
    //for (int i = 1; i <= n; i++) printf("%s\n", s + sa[i]);
    return 0;
}
