/*************************************************************************
	> File Name: 4.grade_count.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 01时46分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int score[n];
    int result[4] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
        (score[i] >= 90 && score[i] <=100) && result[0]++;
        (score[i] >= 80 && score[i] <=89) && result[1]++;
        (score[i] >= 60 && score[i] <=79) && result[2]++;
        (score[i] <= 60) && result[3]++;
    }
    printf("You %d\nLiang %d\nZhong %d\nCha %d", result[0], result[1], result[2], result[3]);
    return 0;
}
