/*************************************************************************
	> File Name: 4.HZOJ505.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月13日 星期三 18时52分11秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int n;
string str[MAX_N + 5];

int cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    sort(str, str + n, cmp);
    string ans = "";
    for (int i = 0; i < n; i++) ans += str[i];
    cout << ans << endl;
    return 0;
}
