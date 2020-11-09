/*************************************************************************
	> File Name: 32.HOJ461.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 20时09分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

typedef struct student {
    char c;
    string level;
    int grade;
} Student;

Student s[max_n + 5];

int main() {
    int n, count = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].c;
        if (s[i].c == 'C') {
            cin >> s[i].level;
            count++;
        } 
        else {
            cin >> s[i].grade;
            sum += s[i].grade;
        } 
    }
    cout << count << " " << sum / (n - count);
    return 0;
}
