/*************************************************************************
	> File Name: 4.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月07日 星期二 18时56分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define MAX_OP 1000000
using namespace std;

int main() {
    srand(time(0));
    int n = 0, m = 0;
    for (int i = 0; i < MAX_OP; i++) {
        double x = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1); 
        double y = rand() * 1.0 / RAND_MAX * (rand() % 2 ? 1 : -1); 
        if (x * x + y * y <= 1.0) m++;
        n++;
    }
    printf("%lf\n", 4 * m * 1.0 / n);
    return 0;
}
