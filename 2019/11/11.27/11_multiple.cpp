/*************************************************************************
	> File Name: 11_multiple.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 19时34分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b - 11; i++) {
        if (i % 11 == 0) printf("%d ", i);
    }
    if (a <= b - 10){
        for (int i = b - 10; i <= b; i++) {
            if (i % 11 == 0) printf("%d", i);
        }
    }else {
        for (int i = a; i <= b; i++){
            if (i % 11 == 0) printf("%d", i);
        }
    }
    return 0;
}
