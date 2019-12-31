/*************************************************************************
	> File Name: 3.EP17.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 15时07分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<inttypes.h>
using namespace std;

int arr1[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

int arr2[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};


int get_len(int n ) {
    if (n < 20) return arr1[n];
    else if (n < 100) {
        return arr2[n / 10] + arr1[n % 10];
    }else if (n < 1000) {
        if (n % 100 == 0) return arr1[n / 100] + 7;
        return arr1[n / 100] + 10 + get_len(n  % 100);
    } return 11;
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += get_len(i);
    }
    printf("%d\n", sum);
    return 0;
}
