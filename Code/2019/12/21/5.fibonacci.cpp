/*************************************************************************
	> File Name: 5.fibonacci.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 13时15分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define max_n 1000
using namespace std;

char ret[max_n + 5] = {0};

void plus(char *p1, char *p2) {
    int len1 = strlen(p1), len2 = strlen(p2);
    ret[max_n + 5] = {0};
    for (int i = 0; i < len2; i++) {
        ret[i] = p1[i] + p2[i];
    }
    for (int i = len2; i < len1; i++) {
        ret[i] = p1[i];
    }
    for (int i = 0; i < len1; i++) {
        if (ret[i] >= 10) {
            ret[i] = ret[i] % 10;
            ret[i + 1] = ret[i] / 10;
        }
    }
}

int main() {
    int n = 2;
    char fib[3][max_n + 5] = {
        {0}, {1}, {1}
    };

    while (strlen(fib[n % 3]) < 1000) {
        if (strlen(fib[(n - 1) % 3]) > strlen(fib[n % 3])){
            plus(fib[(n - 1) % 3], fib[n % 3]);
            strcpy(fib[(n - 2) % 3], ret);
        }else {
            plus(fib[n % 3], fib[(n - 1) % 3]); 
            strcpy(fib[(n - 2) % 3], ret);
        }
        n++;
    }
   
    printf("%s\n", fib[n % 3]);
    return 0;
}
