/*************************************************************************
	> File Name: 4.HZOJ589.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 18时36分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, k, id;

int gcd(int n, int k) {
    return k ? gcd(k, n % k) : n;
}

int main() {
    cin >> n >> k >> id;
    int d = gcd(n, k);
    n /= d;
    k /= d;
    cout << k << "/" << n << endl;
    return 0;
}
