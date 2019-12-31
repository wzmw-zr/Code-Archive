/*************************************************************************
	> File Name: 1.EP19.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月31日 星期二 08时15分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int main() {
    int cnt = 0;
    int y = 1901, m = 1, d = 1;
    int y_1, m_1, d_1;
    while (y <= 2000) {
        while (m <= 12) {
            y_1 = y, m_1 = m, d_1 = d;
            if (m_1 == 1 || m_1 == 2) y_1--, m_1 += 12;
            int x = (y_1 - 1 + (int)floor(y_1 / 4) - (int)floor(y_1 / 100) + (int)floor(y_1 / 400) + 13 * (m_1 + 1) / 5 + d_1);
            while (x < 0) x += 7;
            x %= 7;
            x == 0 && cnt++;
            m++;
        }
        y++;
        m = 1;
    }
    cout << cnt << endl;
    return 0;
}
