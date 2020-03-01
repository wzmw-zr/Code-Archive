/*************************************************************************
	> File Name: 3.264.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月01日 星期日 17时51分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define MAX_N 100000
long h[MAX_N + 5];
long l[MAX_N + 5], r[MAX_N + 5];
int s[MAX_N + 5], top = -1;

int main() {
    int n;
    cin >> n;
    s[0] = s[n + 1] = -1;
    for (int i = 1; i <= n; i++) cin >> h[i];
    s[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (h[i] <= h[s[top]]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (h[i] <= h[s[top]]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
