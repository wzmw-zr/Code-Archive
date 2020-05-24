/*************************************************************************
	> File Name: a.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 19时11分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

long a, b, p;

int main() {
    cin >> a >> b >> p;
    long ans = 1, t = a;
    while (b) {
        if (b & 1) ans = (ans * t) % p;
        t = (t * t) % p; 
        b >>= 1;
    }
    cout << ans << endl;
    return 0;
}
