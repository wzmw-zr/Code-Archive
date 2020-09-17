/*************************************************************************
	> File Name: 3.Suffix_array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月17日 星期四 15时58分18秒
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
#include<algorithm>
using namespace std;
#define MAX_N 1000010

char s[MAX_N];
int n, w, sa[MAX_N], rk[MAX_N << 1], old_rk[MAX_N << 1];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
    for (w = 1; w < n; w <<= 1) {
        sort(sa + 1, sa + n, [](int x, int y) {
            return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
        });
        memcpy(old_rk, rk, sizeof(rk));
        for (int p = 0, i = 1; i <= n; i++) {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] && old_rk[sa[i] + w] == old_rk[sa[i - 1] + w])  rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
    printf("\n");
    return 0;
}
