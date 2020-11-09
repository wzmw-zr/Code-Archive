/*************************************************************************
	> File Name: high_benefit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 01时44分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    float x;
    int n;
    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        x *= 1.06;
    }
    int result = (int) x;
    printf("%d", result);
    return 0;
}
