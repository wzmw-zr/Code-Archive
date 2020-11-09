/*************************************************************************
	> File Name: 33.HOJ462.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 20时17分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
using namespace std;

typedef struct info {
    char c;
    string s;
    long qq;
    long sex = 1;
} Info;

Info inf[max_n + 5];

int main() {
    long n;
    long male = 0, female = 0, sum = 0;
    cin >> n;
    for (long i = 1; i <= n; i++) {
        cin >> inf[i].c;
        if (inf[i].c == 'q') {
            cin >> inf[i].qq;
            sum += inf[i].qq;
        } else {
            cin >> inf[i].s;
            long temp = inf[i].s[inf[i].s.length() - 2] - '0';
            if (temp & 1) {
                male++;
            } else {
                inf[i].sex = 0;
                female++;
            }
        }
    }
    cout << male << " " << female << " " <<  sum  / (n - male - female);
    return 0;
}
