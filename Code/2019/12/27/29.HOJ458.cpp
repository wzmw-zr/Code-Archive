/*************************************************************************
	> File Name: 29.HOJ458.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时57分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
using namespace std;

typedef struct student {
    string name;
    string sex;
    int year, month;
} Student;

Student s[max_n + 5];

int cmp(Student s1, Student s2) {
    if (s1.year < s2.year) return 0;
    else if (s1.year == s2.year) return s1.month > s2.month;
    return 1;
} 

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name >> s[i].sex >> s[i].year >> s[i].month;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        i == n && cout << s[i].name << " " << s[i].sex << " " << s[i].year << " " << s[i].month;
        i != n && cout << s[i].name << " " << s[i].sex << " " << s[i].year << " " << s[i].month << endl;
    }
    return 0;
}
