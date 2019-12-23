/*************************************************************************
	> File Name: 4.EP13.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 15时45分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define max_n 50
using namespace std;

int main() {
    char str[max_n + 5] = {0}, ans[max_n + 5] = {0};
    while (~scanf("%s", str)) {
        int len = strlen(str);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; i < len; i++) {
            ans[len - i] += str[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
        //if (ans[ans[0]] >= 10) {
        //    ans[ans[0]] %= 10;
        //    ans[ans[0] + 1] = ans[ans[0]] / 10;
        //    ans[0]++;
        //}  
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
