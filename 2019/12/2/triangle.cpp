/*************************************************************************
	> File Name: triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 02时12分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main() {
    int c, count = 0;
    scanf("%d", &c);
    for (int i = 1; i < c; i++) {
        int j = (int) sqrt(c * c - i * i);
        for(int k = j; k <= j + 10; k++) {
            if (i *  i + j * j == c * c) 
            count ++;
        }
    }
    printf("%d", count / 2);
    return 0;
}
