/*************************************************************************
	> File Name: 2.HZOJ489.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月01日 星期五 17时40分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000

int n;
int f[MAX_N + 5], g[MAX_N + 5];


int main() {
    cin >> n;
    f[1] = 9, g[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (9 * f[i - 1] + g[i - 1]) % 12345;
        g[i] = (9 * g[i - 1] + f[i - 1]) % 12345;
    }
    cout << (f[n] - f[n - 1] + 12345) % 12345 << endl;
    return 0;
}
