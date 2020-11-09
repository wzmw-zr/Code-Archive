/*************************************************************************
	> File Name: 5.HOJ207.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 23时41分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 50
using namespace std;

typedef struct student {
    string name;
    int score[5] = {0};
    int sum = 0;
} Student;

Student s[max_n + 5];

int cmp(Student s1, Student s2) {
    return s1.sum < s2.sum;
}
int main() {
    int n; 
    int cnt =  0;
    int score[(max_n + 5) * 5] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name;
        for (int j = 1; j <= 4; j++) {
            cin >> s[i].score[j];
            score[cnt++] = s[i].score[j];
        }
        s[i].sum += s[i].score[1] + s[i].score[2] + s[i].score[3] + s[i].score[4];
    }
    for (int i = 1; i <= n; i++) cout << s[i].sum <<endl;
    sort(s + 1, s + n + 1, cmp);
    cout << s[n].name << endl;
    sort(score, score + cnt);
    cout << score[cnt - 1] << " " << score[0] << endl;
    return 0;
}
