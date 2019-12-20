/*************************************************************************
	> File Name: 3.printf.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 16时30分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    char str[100], str2[100];
    int ret;
    /*while (ret = scanf("%[^\n]s", str)) {
        printf("%s ret = %d\n", str, ret);
    }*/
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    scanf("%[^\n]s", str);
    getchar();
    sprintf(str2, "%d.%d.%d.%d", a, b, c, d);
    // FILE *fp = fopen("out.txt", "wb");
    fprintf(stdout, "stdout = %s\n", str2);
    fprintf(stderr, "stderr = %s\n", str2);
    printf("%s", str2);
    return 0;
}
