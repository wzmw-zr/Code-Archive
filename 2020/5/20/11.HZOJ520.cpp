/*************************************************************************
	> File Name: 11.HZOJ520.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 20时59分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

long a;

int main() {
    cin >> a;
    for (long k = a; ; k++) {
        long s1 = k * (k - 1) / 2;
        for (long n = k + 1; ; n++) {
            long s2 = (n + k + 1) * (n - k) / 2;
            if (s1 == s2) {
                cout << k << " " << n << endl;
                return 0;
            }
            if (s1 < s2) break;
        }
    }
    return 0;
}
