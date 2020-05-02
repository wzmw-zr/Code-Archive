/*************************************************************************
	> File Name: 2.HZOJ227.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月02日 星期六 09时52分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

long a, b, p;

long quick_mul() {
    long tmp = a, ans = 0;
    while (b) {
        if (b & 1) ans += (ans + tmp) % p;
        tmp = tmp * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    cin >> a >> b >> p;
    cout << quick_mul() << endl;
    return 0;
}
