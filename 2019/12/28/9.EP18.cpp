/*************************************************************************
	> File Name: 9.EP18.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 16时36分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 20
using namespace std;

int num[max_n + 5][max_n + 5] = {0};
int max_num[max_n + 5][max_n + 5] = {0};

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) cin >> num[i][j];
    }
    
    for (int i = 0; i <= 14; i++) max_num[14][i] = num[14][i];

    for (int i = 13; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            max_num[i][j] = max(max_num[i + 1][j], max_num[i + 1][j + 1]) + num[i][j];
        }
    }
    cout << max_num[0][0] << endl;
    return 0;
}

