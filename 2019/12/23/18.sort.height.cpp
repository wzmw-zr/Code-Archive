/*************************************************************************
	> File Name: 18.sort.height.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 17时35分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000
#define max_l 300
using namespace std;

int people[max_n + 5] = {0};
int height[max_l + 5][max_n + 5] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &people[i]);
        height[people[i]][0]++;
        height[people[i]][height[people[i]][0]] = i;
    }
    for (int i = 1; i <= max_l; i++) {
        if (height[i][0] == 0) continue;
        for (int j = 1; j <= height[i][0]; j++) {
            n--;
            n && printf("%d ", height[i][j]);
            !n && printf("%d", height[i][j]);
        }
    }
    return 0;
}
