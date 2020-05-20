/*************************************************************************
	> File Name: 6.HZOJ516.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 19时40分03秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#define MAX_N 100005

long n, ans;
long c[MAX_N + 5], w[MAX_N + 5];
long c_cnt, w_cnt;
string str;

int main() {
    cin >> n >> str;
    for (long i = 0; i < n; i++) {
        if (str[i] == 'C') c_cnt++;
        c[i] = c_cnt;
    }
    for (long i = n - 1; i >= 0; i--) {
        if (str[i] == 'W') w_cnt++;
        w[i] = w_cnt;
    }
    for (long i = 0; i < n; i++) {
        if (str[i] == 'O') ans += c[i] * w[i];
    }
    cout << ans << endl;
    return 0;
}
