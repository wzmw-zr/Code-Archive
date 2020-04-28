/*************************************************************************
	> File Name: 11.HZOJ264.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 20时47分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

long a[MAX_N + 5];
long s[MAX_N + 5], top = -1;
long l[MAX_N + 5], r[MAX_N + 5];

int main() {
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n + 1] = -1;
    s[top = 0] = 0;
    for (int i = 1; i <= n; i++) {
        while (top >= 0 && a[s[top]] >= a[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    s[top = 0] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top >= 0 && a[s[top]] >= a[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] * (r[i] - l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
