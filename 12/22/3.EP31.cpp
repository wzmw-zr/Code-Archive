/*************************************************************************
	> File Name: 3.EP31.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 14时30分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define max_n 8
#define max_m 200
using namespace std;

int money[max_n + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[max_m + 5] = {0};


int main() {
    f[0] = 1;
    for (int i = 0; i < max_n; i++) {
        for (int j = 1; j <= max_m; j++) {
            if (j >= money[i]) f[j] += f[j - money[i]];
        }
    }
    printf("%d\n", f[max_m]);
    return 0;
}
