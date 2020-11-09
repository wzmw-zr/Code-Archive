/*************************************************************************
	> File Name: multiply.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 19时19分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    long n, temp;
    scanf("%ld", &n);
    long result = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%ld", &temp);
        result *= temp;
    }
    printf("%ld", result);
    return 0;
}
