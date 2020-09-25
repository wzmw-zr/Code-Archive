/*************************************************************************
	> File Name: 4.SA_height.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月25日 星期五 16时06分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define LOG_N 30
#define MAX_N 100010

char s[MAX_N + 5];
int logn[MAX_N + 5];
int height[MAX_N + 5][LOG_N + 5];
int sa[MAX_N << 1], rk[MAX_N << 1], old_rk[MAX_N << 1];
int n, w, i, j, k, p;

void init_log() {
    logn[1] = 0;
    logn[2] = 1;
    for (i = 3; i <= MAX_N; i++) logn[i] = logn[i / 2] + 1;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
    for (w = 1; w <= n; w <<= 1) {
        sort(sa + 1, sa + n, [](int a, int b){ return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b]; });
        memcpy(old_rk, rk, sizeof(rk));
        for (i = 1, p = 0; i <= n; i++) {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] && old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
    init_log();
    for (i = 1, k = 0; i <= n; i++) {
        if (k) k--;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) k++;
        height[rk[i]][0] = k;
    }
    for (i = 1; i <= LOG_N; i++) {
        for (j = 1; j + (1 << i) - 1 <= n; j++) {
            height[j][i] = max(height[j][i - 1], height[j + (1 << (i - 1))][i - 1]);
        }
    }
    return 0;
}
