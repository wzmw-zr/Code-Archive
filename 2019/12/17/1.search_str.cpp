/*************************************************************************
	> File Name: 1.search_str.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 18时07分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<starg.h>
using namespace std;


int is_same(char *a, char *b, int i) {
    int len_a = strlen(a), len_b = strlen(b), flag = 0;
    for (int j = 0; j < len_b; j++) {
        if (a[i + j] == b[j]) continue;
        flag = 1;
        break;
    } 
}


int main() {
    char a[1005], b[1005];
    scanf("%[^\n]s", a);
    scanf("%[^\n]s", b);
    int count = 0;
    int len_a = strlen(a), len_b = strlen(b);
    for (int i = 0; i < len_a - len_b; i++) {
        if (is_same(a, b, i)) count++;
    }
    printf("%d", count);
    return 0;
}
