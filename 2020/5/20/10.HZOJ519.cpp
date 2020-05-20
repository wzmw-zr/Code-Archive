/*************************************************************************
	> File Name: 10.HZOJ519.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 20时45分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

long a, b, ans;

int main() {
    cin >> a >> b;
    for (long i = 0; i <= 9; i++) {
        for (long j = 0; j <= 9; j++) {
            if (i == j) continue;
            for (int k = 3; k <= 17; k++) {
                for (int l = 1; l <= k; l++) {
                    if (j == 0 && l == 1) continue;
                    if (i == 0 && l != 1) break;
                    long t = 0;
                    for (int m = 1; m <= k; m++) {
                        if (m != l) t = t * 10 + i;
                        else t = t * 10 + j;
                    }
                    if (t >= a && t <= b) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
