/*************************************************************************
	> File Name: farm.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 02时09分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main() {
    double n, m;
    scanf("%lf%lf", &n, &m);
    printf("%.0lf", ceil(n / m));
    return 0;
}
