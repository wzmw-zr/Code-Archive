/*************************************************************************
	> File Name: 4.HOJ56.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月02日 星期四 16时52分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 10
using namespace std;

int num[max_n + 5] = {0};
int marked[max_n + 5] = {0};
int fac[max_n + 5] = {0};

void init(int x) {
    fac[0] = 1, fac[1] = 1;
    for (int i = 1; i <= x; i++) num[i] = i, marked[i] = 1, fac[i] = i * fac[i - 1];
}

void get_num(int x, int y) {
    int m = x, index = 1;
    while (y) {
        int number = y / fac[m];
        y %= fac[m];
        int temp = 1, res = 0;
        while (temp <= number) {
            res++;
            temp += (marked[res] == 1);
        }
        marked[res] = 0;
        num[index++] = res;
        m--;
    }
}

int main() {
    int x ,y;
    cin >> x >> y;
    init(x);
    get_num(x, y);
    for (int i = 1; i <= x; i++) cout << num[i];
    cout << endl;
}
