/*************************************************************************
	> File Name: avergae.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 18时59分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    double result = 0;
    int temp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        result += temp;
    }
    printf("%.2lf", result / n);
    return 0;
}
