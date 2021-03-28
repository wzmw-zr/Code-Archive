/*************************************************************************
	> File Name: 2.LeetCode5716.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月29日 星期一 00时49分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

const long mod = 1e9 + 7;

long pow(long x, long cnt) {
    long t = x;
    long ans = 1;
    while (cnt) {
        if (cnt & 1) ans = (ans * t) % mod;
        t = (t * t) % mod;
        cnt = cnt >> 1;
    }
    return ans;
}

long maxNiceDivisors(long primeFactors) {
    if (primeFactors <= 3) return primeFactors;
    long rest = primeFactors % 3;
    long x;
    if (rest == 0) x = primeFactors / 3;
    else if (rest == 1) x = (primeFactors - 4) / 3;
    else x = primeFactors / 3;
    long ans = pow(3, x);
    if (rest == 1) ans = (ans * 4) % mod;
    else if (rest == 2) ans = (ans * 2) % mod;
    return ans;
}

int main() {
    long primeFactors;
    cin >> primeFactors;
    cout << maxNiceDivisors(primeFactors) << endl;
    return 0;
}
