/*************************************************************************
	> File Name: 8.HOJ220.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月02日 星期四 22时11分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 100
using namespace std;

typedef struct student {
    string name;
    int chinese, math, english, science, sum;
} Student;

Student s[max_n + 5];

int cmp1(Student s1, Student s2) {
    if (s1.chinese == s2.chinese) return s1.name < s2.name;
    return s1.chinese > s2.chinese;
}

int cmp2(Student s1, Student s2) {
    if (s1.math == s2.math) return s1.name < s2.name;
    return s1.math > s2.math;
}

int cmp3(Student s1, Student s2) {
    if (s1.english == s2.english) return s1.name < s2.name;
    return s1.english > s2.english;
}

int cmp4(Student s1, Student s2) {
    if (s1.science == s2.science) return s1.name < s2.name;
    return s1.science > s2.science;
}

int cmp5(Student s1, Student s2) {
    if (s1.sum == s2.sum) return s1.name < s2.name;
    return s1.sum > s2.sum;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name >> s[i].chinese >> s[i].math >> s[i].english >> s[i].science;
        s[i].sum = s[i].chinese + s[i].math + s[i].english + s[i].science;
    }
    sort(s + 1, s + n + 1, cmp1);
    for (int i = 1; i <= 4; i++) {
        i == 4 && (cout << s[i].name << endl);
        i != 4 && (cout << s[i].name << " ");
    }
    sort(s + 1, s + n + 1, cmp2);
    for (int i = 1; i <= 4; i++) {
        i == 4 && (cout << s[i].name << endl);
        i != 4 && (cout << s[i].name << " ");
    }
    sort(s + 1, s + n + 1, cmp3);
    for (int i = 1; i <= 4; i++) {
        i == 4 && (cout << s[i].name << endl);
        i != 4 && (cout << s[i].name << " ");
    }
    sort(s + 1, s + n + 1, cmp4);
    for (int i = 1; i <= 4; i++) {
        i == 4 && (cout << s[i].name << endl);
        i != 4 && (cout << s[i].name << " ");
    }
    sort(s + 1, s + n + 1, cmp5);
    for (int i = 1; i <= 4; i++) {
        i == 4 && (cout << s[i].name << endl);
        i != 4 && (cout << s[i].name << " ");
    }
}
