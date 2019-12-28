/*************************************************************************
	> File Name: 11.HOJ43.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 18时09分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int num[max_n + 5][max_n + 5];

int main() {
    memset(num, 0, sizeof(num));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cin >> num[i][j];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
    }
    cout << num[0][0] <<endl;
    return 0;
}
