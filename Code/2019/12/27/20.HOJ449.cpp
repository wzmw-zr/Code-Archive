/*************************************************************************
	> File Name: 20.HOJ449.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 17时55分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 30
using namespace std;

int num[max_n + 5][max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    num[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] = num[i - 1][j] + num[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            j == i && cout << num[i][j];
            j != i && cout << num[i][j] << " ";
        }
        i != n && cout << endl;
    }
    return 0;
}
