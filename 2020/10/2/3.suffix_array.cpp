/*************************************************************************
	> File Name: 3.suffix_array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月02日 星期五 12时48分30秒
 ************************************************************************/

#include<iostream>
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

char s[MAX_N + 5];
int sa[MAX_N << 1 + 10], rk[MAX_N << 1 + 10], old_rk[MAX_N << 1 + 10];
int w, n;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
    for (w = 1; w <= n; w <<= 1) {
        sort(sa + 1, sa + n, [](int a, int b){ return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b]; });
        memcpy(old_rk, rk, sizeof(rk));
        for (int j = 1, p = 0; j <= n; j++) {
            if (old_rk[sa[j]] == old_rk[sa[j] - 1]) rk[sa[j]] = p;
            else rk[sa[j]] = ++p;
        }
    }
    return 0;
}
