/*************************************************************************
	> File Name: 7.HZOJ251.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月17日 星期日 20时44分51秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 10000

int x[MAX_N + 5], y[MAX_N + 5], w[MAX_N + 5];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(y, y + n);
    sort(x, x + n);
    for (int i = 0; i < n; i++) w[i] = x[i] - i;
    sort(w, w + n);
    int sum = 0, cy = y[n / 2], cw = w[n / 2];
    for (int i = 0; i < n; i++) {
        sum += abs(w[i] - cw) + abs(y[i] - cy);
    }
    cout << sum << endl;
    return 0;
}
