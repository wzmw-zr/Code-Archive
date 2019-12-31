/*************************************************************************
	> File Name: EP07-1.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 18时43分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int is_val(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


 int main() {
     int i, count;
     for (i = 2, count = 0; count < 10001; i++) {
         if (is_val(i)) count++;
     }
     printf("%d\n", i - 1);
     return 0;
 }
