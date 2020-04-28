/*************************************************************************
	> File Name: 9.HZOJ490.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 19时12分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 32767
int f[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + 2 - 1) % i + 1;
    }
    int x = n;
    while (f[x] - x) x = f[x];
    cout << n + x << endl;
    return 0;
}
