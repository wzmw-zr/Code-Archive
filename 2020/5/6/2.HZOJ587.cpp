/*************************************************************************
	> File Name: 2.HZOJ587.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 18时03分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, a, b, c;

int main() {
    cin >> n >> a >> b >> c;
    int cnt = 0;
    if (a > b) cnt++;
    if (b > c) cnt++;
    if (c > b) cnt++;
    if (cnt == 1) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
