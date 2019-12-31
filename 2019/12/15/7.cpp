/*************************************************************************
	> File Name: 7.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 20时06分44秒
 ************************************************************************/

#include<iostream>
#include<inttypes.h>
using namespace std;
#define max_n 2550000

//int frac(int n) {
//    if (n == 0) return 0;
//    if (n == 1) return 1;
//    return n * frac(n - 1);
//}

int check(int n, int *a) {
    int sum = 0;
    int x = n;
    while (n != 0) {
        sum += a[n % 10];
        n /= 10;
    }
    if (sum == x) return 1;
    else return 0;
}

int main () {
    int result[10] = {1};
    int sum = 0;
    for (int i = 1; i <= 9; i++) {
        result[i] = result[i - 1] * i;
    }
    for (int i = 3; i <= max_n; i++) {
        if (check(i, result)) sum += i;
    }
    cout << sum;
    return 0;
}
