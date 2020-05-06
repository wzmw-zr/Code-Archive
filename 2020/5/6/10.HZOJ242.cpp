/*************************************************************************
	> File Name: 10.HZOJ242.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 20时18分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

int n, m;
double mmax;
int num[MAX_N + 5];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];   
        num[i] += num[i - 1];
    }
    for (int i = m; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            mmax = max(mmax, 1.0 * (num[j + i - 1]) - num[j] / i);
        }
    }
    printf("%.0lf\n", mmax * 1000);
    return 0;
}
