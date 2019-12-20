/*************************************************************************
	> File Name: someday_date.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 18时14分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    int year, month, day, h;
    scanf("%d%d%d", &year, &month, &day);
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    h = (day + (26 * (month + 1)) / 10 + (year % 100) + (year % 100) / 4 + (year / 100) / 4 + 5 * (year / 100)) % 7;
    if (h == 0 || h == 1) printf("%d", h + 6);
    else printf("%d", h - 1);
    return 0;
}
