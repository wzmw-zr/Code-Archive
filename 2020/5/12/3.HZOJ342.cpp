/*************************************************************************
	> File Name: 3.HZOJ342.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月12日 星期二 20时39分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

long k;
long a[5];

int solve(int k) {
    long full_size = 1;
    for (long i = 0; i < k; i++) {
        a[i] = 0;
        cin >> a[i]; 
        full_size *= a[i];
    }
    long f[a[0] + 5][a[1] + 5][a[2] + 5][a[3] + 5][a[4] + 5];
    memset(f, 0, sizeof(long) * full_size);
    f[0][0][0][0][0] = 1;
    for (long i1 = 0; i1 <= a[0]; i1++) {
    for (long i2 = 0; i2 <= a[1]; i2++) {
    for (long i3 = 0; i3 <= a[2]; i3++) {
    for (long i4 = 0; i4 <= a[3]; i4++) {
    for (long i5 = 0; i5 <= a[4]; i5++) {
        long val = f[i1][i2][i3][i4][i5];
        if (i1 < a[0] && i1 >= i2 && i1 >= i3 && i1 >= i4 && i1 >= i5) f[i1 + 1][i2][i3][i4][i5] += val;
        if (i2 < a[1] && i2 >= i3 && i2 >= i4 && i2 >= i5) f[i1][i2 + 1][i3][i4][i5] += val;
        if (i3 < a[2] && i3 >= i4 && i3 >= i5) f[i1][i2][i3 + 1][i4][i5] += val;
        if (i4 < a[3] && i4 >= i5) f[i1][i2][i3][i4 + 1][i5] += val;
        if (i5 < a[4]) f[i1][i2][i3][i4][i5 + 1] += val;
    }}}}}
    cout << f[a[0]][a[1]][a[2]][a[3]][a[4]] << endl;
    return 0;
}

int main() {
    long k;
    while ((cin >> k)) {
        if (k == 0) break;
        solve(k);
    }
}
