/*************************************************************************
	> File Name: 1.HZOJ513.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 18时08分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int m, t, ans;

int check(int n) {
    while (n) {
        if ((n % 10) == t) return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        if (check(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
