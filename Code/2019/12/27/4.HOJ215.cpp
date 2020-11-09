/*************************************************************************
	> File Name: 4.HOJ215.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 14时18分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 40
using namespace std;

typedef struct student {
    string name;
    int score[5] = {0};
    int sum = 0;
} Student;

Student s[max_n + 5];

int cmp(Student s1, Student s2) {
    if (s1.sum >= s2.sum) return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name >> s[i].score[1] >> s[i].score[2] >> s[i].score[3] >> s[i].score[4];
        for (int j = 1; j <= 4; j++) s[i].sum += s[i].score[j];
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= 3; i++) {
        i == 3 && cout << s[i].name;
        i != 3 && cout << s[i].name << endl;
    }
    return 0;
}
