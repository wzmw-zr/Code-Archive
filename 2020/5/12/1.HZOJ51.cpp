/*************************************************************************
	> File Name: 1.HZOJ51.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月12日 星期二 18时06分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
#define MAX_N 1000
int f[MAX_N + 5];
int a[MAX_N + 5]; // underneath squeezing white block number
int s[MAX_N + 5], top = -1;
int n, m, ans;

int main() {
    cin >> n >> m;
    a[m + 1] = -1;
    f[m + 1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, val; j <= m; j++) {
            cin >> val;
            if (val == 1) a[j] += 1;
            else a[j] = 0;
        }
        top = -1;
        s[++top] = m + 1;
        for (int j = m; j >= 1; j--) {
            while (top != -1 && a[s[top]] >= a[j]) top--; 
            f[j] = (s[top] - j) * a[j] + f[s[top]];
            f[j] %= 100007;
            s[++top] = j;
            ans += f[j];
            ans %= 100007;
        }
    }
    cout << ans << endl;
    return 0;
}
