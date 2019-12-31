/*************************************************************************
	> File Name: 6.search_str.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 01时54分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int main () {
    char a[1005], b[1005];
    scanf("%[^\n]s%[^\n]s", a, b);
   /* int len_a = strlen(a), len_b = strlen(b), cnt = 0;
    for (int i = 0; i < len_a - len_b; i++) {
        int flag = 0;
        for (int j = 0; j < len_b; j++) {
            if (a[i + j] == b[j]) continue;
            else {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        else cnt++;
    }
    */
    printf("%s\n%s", a, b);    
    return 0;
}
