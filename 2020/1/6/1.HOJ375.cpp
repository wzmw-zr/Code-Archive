/*************************************************************************
	> File Name: 1.HOJ375.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 08时25分53秒
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
#define max_n 300
using namespace std;

typedef struct student {
    int number;
    int chinese, math, english, sum;
} Student;

Student s[max_n + 5];

int cmp(Student s1, Student s2) {
    if (s1.sum != s2.sum) return s1.sum > s2.sum;
    if (s1.chinese != s2.chinese) return s1.chinese > s2.chinese;
    return s1.number < s2.number;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        s[i].number = i;
        cin >> s[i].chinese >> s[i].math >> s[i].english;
        s[i].sum = s[i].chinese + s[i].math + s[i].english;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= 5; i++) cout << s[i].number << " " << s[i].sum << endl;
    return 0;
}
