/*************************************************************************
	> File Name: 2.prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月04日 星期六 08时49分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
using namespace std;

int max_prime(int n) {
    int ans = 1, i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans = i;
        }
        i++;
    }
    if (n > 1) ans = n;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << max_prime(n) << endl;
    return 0;
}
