/*************************************************************************
	> File Name: 13.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 16时36分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 10
using namespace std;

int num[max_n + 5] = {0};

void sort() {
    for (int i = 10; i >= 2; i--) {
        for (int j = 1; j < i; j++) {
            if (num[j] >= num[j + 1]) continue;
            int temp = num[j];
            num[j] = num[j + 1];
            num[j + 1] =  temp;
        }
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &num[i]);
    }
    sort();
    for (int i = 1; i <= 10; i++) {
        i == 10 && printf("%d", num[i]);
        i != 10 && printf("%d ", num[i]);
    }
    return 0;
}
