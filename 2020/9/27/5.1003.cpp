/*************************************************************************
	> File Name: 5.1003.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月27日 星期日 12时59分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

#define MAX_S 800010

int t, w, n;
char s[MAX_S + 5];
int sa[MAX_S << 1], rk[MAX_S << 1], old_rk[MAX_S << 1]; 
int height[MAX_S + 5];

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(s, 0, sizeof(s));
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
        for (w = 1; w <= n; w <<= 1) {
            sort(sa + 1, sa + n, [](int a, int b){ return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b];});
            memcpy(old_rk, rk, sizeof(rk));
            for (int i = 1, p = 0; i <= n; i++) {
                if (old_rk[sa[i]] == old_rk[sa[i - 1]] && old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = p;
                else rk[sa[i]] = ++p;
            }
        }
        for (int i = 2, l = 0; i <= n; i++) {
            if (l) l--;
            while (s[i + l] == s[sa[rk[i] - 1] + l]) l++;
            height[rk[i]] = l;
        }

        for (int i = 2; i <= n; i++) {
        }
    }
    return 0;
}
