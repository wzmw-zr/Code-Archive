/*************************************************************************
	> File Name: test_endtime.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 00时57分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int h, m, s, t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    h += t / 3600;
    m += (t % 3600) / 60;
    s += t % 60;
    int second = s % 60;
    int minute = (m + s / 60) % 60;
    int hour = h + (m + s / 60) / 60;
    double percent = (double)t / 86400;
    hour %= 24;
    if (hour == 0) printf("%d:%d:%dam\n%.2lf%%",12, minute, second, percent * 100);
    if (0 < hour && hour <= 11) printf("%d:%d:%dam\n%.2lf%%", hour, minute, second, percent * 100);
    if (hour == 12) printf("%d:%d:%dpm\n%.2lf%%", 12, minute, second, percent * 100);
    if (hour >= 13 && hour <= 23) printf("%d:%d:%dpm\n%.2lf%%", hour - 12, minute, second, percent * 100);
    return 0;
}
