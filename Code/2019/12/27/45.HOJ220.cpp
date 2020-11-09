/*************************************************************************
	> File Name: 45.HOJ220.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 23时47分25秒
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
    int chinese, math, english, science, sum;
} Student;

Student s[max_n + 5];

int cmp(Student s1, Student s2) {
    if (s1.name.compare(s2.name) >= 0) return 1;
    return 0;
}

int cmp1(Student s1, Student s2) {
    if (s1.chinese == s2.chinese) {
        if (s1.name.compare(s2.name) >= 0) return 1;
        return 0;
    }
    return s1.chinese > s2.chinese;
}

int cmp2(Student s1, Student s2) {
    if (s1.math == s2.math) {
        if (s1.name.compare(s2.name) >= 0) return 1;
        return 0;
    }
    return s1.math >= s2.math;
}

int cmp3(Student s1, Student s2) {
    if (s1.english == s2.english) {
        if (s1.name.compare(s2.name) >= 0) return 1;
        return 0;
    }
    return s1.english >= s2.english;
}

int cmp4(Student s1, Student s2) {
    if (s1.science == s2.science) {
        if (s1.name.compare(s2.name) >= 0) return 1;
        return 0;
    }
    return s1.science >= s2.science;
}
int cmp5(Student s1, Student s2) {
    if (s1.sum == s2.sum) {
        if (s1.name.compare(s2.name) >= 0) return 1;
        return 0;
    }
    return s1.sum >= s2.sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name >> s[i].chinese >> s[i].math >> s[i].english >> s[i].science;
        s[i].sum = s[i].chinese + s[i].math + s[i].english + s[i].science;
    }
    sort(s + 1, s + n + 1, cmp);
    sort(s + 1, s + n + 1, cmp1);
    for (int i = 1; i <= 4; i++) {
        i == 4 && cout << s[i].name << endl;
        i != 4 && cout << s[i].name << " ";
    }
    sort(s + 1, s + n + 1, cmp2);
    for (int i = 1; i <= 4; i++) {
        i == 4 && cout << s[i].name << endl;
        i != 4 && cout << s[i].name << " ";
    }
    sort(s + 1, s + n + 1, cmp3);
    for (int i = 1; i <= 4; i++) {
        i == 4 && cout << s[i].name << endl;
        i != 4 && cout << s[i].name << " ";
    }
    sort(s + 1, s + n + 1, cmp4);
    for (int i = 1; i <= 4; i++) {
        i == 4 && cout << s[i].name << endl;
        i != 4 && cout << s[i].name << " ";
    }
    sort(s + 1, s + n + 1, cmp5);
    for (int i = 1; i <= 4; i++) {
        i == 4 && cout << s[i].name << endl;
        i != 4 && cout << s[i].name << " ";
    }
    return 0;
}
