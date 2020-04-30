/*************************************************************************
	> File Name: 4.HZOJ43.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 18时33分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000

int n;
int f[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    int mmax = f[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i - 1][j], f[i - 1][j - 1]);
            mmax = max(mmax, f[i][j]);
        }
    }
    cout << mmax << endl;
    return 0;
}
