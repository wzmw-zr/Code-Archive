/*************************************************************************
	> File Name: number_count.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 19时44分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    int a, b, pre;
    for (int i = a; i <= b; i++) {
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                int x = i / 100;
                int y = i % 100;
                for (int k = 1; k <= sqrt(x); k++)
            }
        }
    }
    return 0;
}
