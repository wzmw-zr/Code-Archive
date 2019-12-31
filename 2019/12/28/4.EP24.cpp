/*************************************************************************
	> File Name: 4.EP24.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 11时58分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10
using namespace std;

int jump_num[max_n + 5] = {0};
int num[max_n + 5] = {0};

void init() {
    jump_num[0] = 1, num[0] = 1;
    for (int i = 1; i < 10; i++) {
        jump_num[i] = i * jump_num[i - 1];
        num[i] = 1;
    }
}



int main() {
    init();
    int n, k;
    cin >> n >> k;
    int i = 9;
    while (k) {
        int x = k / jump_num[i], j = -1;
        for (int k = 0; k < 10; k++) {
            j++;
            x -= num[k];
        }
        cout << j << " ";
        k %= jump_num[i];
        i--;
    }
    return 0;
}
