/*************************************************************************
	> File Name: 1.score.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 23时43分32秒
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

int score[max_n + 5] = {0};
int count1[10] = {0};

int cmp(int a, int b) {
    return a >= b;
}

void handle(int x) {
    switch (x / 10) {
        case 10 : count1[1]++; break;
        case 9 : count1[2]++; break;
        case 8 : count1[3]++; break;
        case 7 : count1[4]++; break;
        case 6 : count1[5]++; break;
        default : count1[6]++; break;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
        handle(score[i]);
    }
    sort(score + 1, score + n + 1, cmp);
    for (int i = 1; i <= n; i++) printf("%d\n", score[i]);
    for (int i = 1; i <= 6; i++) {
        i < 6 && printf("%d ", count1[i]);
        i == 6 && printf("%d", count1[i]);
    }
    return 0;
}
