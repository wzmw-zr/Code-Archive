/*************************************************************************
	> File Name: range.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 19时14分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int min, max, temp;
    scanf("%d", &min);
    max = min;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d", &temp);
        if (temp < min) min = temp;
        if (temp > max) max = temp;
    }
    printf("%d", max - min);
    return 0;
}
