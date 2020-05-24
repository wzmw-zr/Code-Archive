/*************************************************************************
	> File Name: 9.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 19时39分30秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX_N 100000

long n, ans;
long num[MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    int p = num[n / 2];
    for (int i = 0; i < n; i++) ans += abs(p - num[i]);
    cout << ans << endl;
    return 0;
}
