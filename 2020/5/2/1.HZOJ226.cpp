/*************************************************************************
	> File Name: 1.HZOJ226.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月02日 星期六 09时36分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

long a, b, p;

long quick_mod() {
    long tmp = a, res = 1; 
    while (b) {
        if (b & 1) {
            res *= a;
            res %= p;
        }
        a = a * a;
        a %= p;
        b >>= 1;
    }
    return res % p;
}

int main() {
    cin >> a >> b >> p;
    cout << quick_mod()<< endl;
    return 0;
}
