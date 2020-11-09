/*************************************************************************
	> File Name: 7_multiple.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 20时25分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) printf("%d\n", i);
    }
    return 0;
}
