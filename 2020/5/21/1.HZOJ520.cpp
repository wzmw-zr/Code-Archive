/*************************************************************************
	> File Name: 1.HZOJ520.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月21日 星期四 15时49分28秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<unistd.h>
using namespace std;

int a;

int main() {
    cin >> a;
    cout << a << endl;
    for (int i = (log(a) - 1) / 2; ; i++) {
        cout << i << endl;
        sleep(1);
        int n = pow(2, 2 * i + 1);
        int t1 = sqrt(n + 1), t2 = sqrt(n - 1);
        if ((t1 * t1 != n + 1) || (t2 * t2 != n - 1)) continue;
        int k = pow(2, i);
        if (t1 * t1 == n + 1) k *= t1;
        else k *= t2;
        cout << k << " " << n << endl;
    }
    return 0;
}
