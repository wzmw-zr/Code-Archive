/*************************************************************************
	> File Name: 1.average.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月25日 星期三 00时16分22秒
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

double score[max_n + 5] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &score[i]);
    sort(score + 1, score + n + 1);
    int k;
    scanf("%d", &k);
    double sum = 0.0;
    for (int i = n; i >= n - k + 1; i--) {
        sum += score[i];
    }
    printf("%.2lf", sum / k);
    return 0;
}
