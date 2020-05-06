/*************************************************************************
	> File Name: 6.HZOJ241.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 18时57分15秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define MAX_N 100000

struct Node {
    long x, y;
};

int n;
Node a[MAX_N + 5], b[MAX_N + 5];


int main() {
    cin >> n;
    double ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; i++) cin >> b[i].x >> b[i].y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double tmp1 = pow(a[i].x - b[j].x, 2);
            double tmp2 = pow(a[i].y - b[j].y, 2);
            ans = min(ans, sqrt(tmp1 + tmp2));
        }
    }
    printf("%.3lf\n", ans);
    return  0;
}
