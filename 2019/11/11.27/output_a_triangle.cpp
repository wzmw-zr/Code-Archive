/*************************************************************************
	> File Name: output_a_triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 20时35分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= 2 * i - 1; j ++) {
            printf("A");
        }
        printf("A\n");
    }
    return 0;
}
