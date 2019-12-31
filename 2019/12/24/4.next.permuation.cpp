/*************************************************************************
	> File Name: 4.next.permuation.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 16时11分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int main() {
    int a[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    while (next_permutation(a, a + 10)) {
        for (int i = 0; i < 10; i++) printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
