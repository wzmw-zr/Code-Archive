/*************************************************************************
	> File Name: 17.HOJ446.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 16时30分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[n][n] = {0};
    int len = (int)ceil(n * 1.0 / 2);
    for (int i = 1; i <= len; i++) {
        for (int j = i - 1; j < n - i + 1; j++) {
            num[i - 1][j] = i;
            num[j][n - i] = i;
            num[n - i][j] = i;
            num[j][i - 1] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            j != n - 1 && cout << num[i][j] << " ";
            j == n - 1 && cout << num[i][j] << endl;
        }
    }
    return 0;
}
