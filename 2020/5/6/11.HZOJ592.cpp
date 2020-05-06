/*************************************************************************
	> File Name: 11.HZOJ592.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 20时44分17秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#define MAX_X 100000
#define DIV 1000000007

string s;
int cnt[100];

int func(int num) {
    int ret = 0;
    for (int i = 0; i < 6; i++) ret += ((num >> i) & 1) ? 0 : 1;
    return ret;
}

void init() {
    for (int i = 0; i <= 64; i++) {
        cnt[i] = func(i);
    }
}

int main() {
    init();
    cin >> s;
    long all = 0;
    for (int i = 0; i < s.size(); i++) {
        int tmp;
        if ('0' <= s[i] && s[i] <= '9') tmp = s[i] - '0';
        else if ('A' <= s[i] && s[i] <= 'Z') tmp = s[i] - 'A' + 10;
        else if ('a' <= s[i] && s[i] <= 'z') tmp = s[i] - 'a' + 36;
        else if (s[i] == '-') tmp = 62;
        else tmp = 63;
        all += cnt[tmp];
    }
    cout << all << endl;
    long res = 1;
    for (int i = 1; i <= all; i++) res = (res * 3) % DIV;
    cout << res << endl;
    return 0;
}
