/*************************************************************************
	> File Name: 7.HOJ218.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时14分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100000
using namespace std;

typedef struct student {
    int number;
    int height;
} Student;

Student s[max_n  + 5];

int cmp(Student s1, Student s2) {
    return s1.height <= s2.height;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        s[i].number = i;
        cin >> s[i].height;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        i == n && cout << s[i].number;
        i != n && cout << s[i].number << " ";
    }
    return 0;
}
