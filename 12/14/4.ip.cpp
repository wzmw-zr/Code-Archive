/*************************************************************************
	> File Name: 4.ip.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 19时08分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


union IP {
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
};

int is_little() {
    int x = 1;
    return ((char *)(&x))[0];
}

int main () {
    union IP p;
    char str[25];
    unsigned int arr[4];
    /*while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
        printf("%d\n", p.num);
    }
*/
    printf("%d\n", is_little());
    return 0;
}
