/*************************************************************************
	> File Name: 8.fac.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 20时37分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define max_n 300
using namespace std;

int num[max_n + 5] = {0};

int main() {
    int sum = 0;
    num[0] = 1, num[1] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= i;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;    
            num[0] += (j == num[0]);
        }
    }
    printf("num[0] = %d\n", num[0]);
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    printf("%d\n", sum);
    return 0;
}
