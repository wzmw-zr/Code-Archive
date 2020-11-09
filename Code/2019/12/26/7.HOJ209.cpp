/*************************************************************************
	> File Name: 7.HOJ209.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 00时34分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
using namespace std;

double score[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> score[i];
    sort(score + 1, score + n + 1);
    for (int i = 1; i <= n; i++) cout << score[i] << endl;
    return 0;
}
