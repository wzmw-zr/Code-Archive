/*************************************************************************
	> File Name: date.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 18时04分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
        printf("Thursday");
        break;

        case 2:
        printf("Friday");
        break;

        case 3:
        printf("Saturday");
        break;

        case 4:
        printf("Sunday");
        break;

        case 5:
        printf("Monday");
        break;

        case 6:
        printf("Tuesday");
        break;

        case 7:
        printf("Wednesday");
        break;
    }
    return 0;
}
