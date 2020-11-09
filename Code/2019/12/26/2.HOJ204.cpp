/*************************************************************************
	> File Name: 2.HOJ204.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 23时14分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 30
using namespace std;


typedef struct line {
    int arrow[max_n + 5] = {0};
} Line;

Line l[max_n + 5];


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> l[i].arrow[j];
        }
    }
    for (int i = 1; i <= n; i++) cout << l[i].arrow[i] <<endl;
    return 0;
}
