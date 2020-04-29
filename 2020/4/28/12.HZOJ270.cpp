/*************************************************************************
	> File Name: 12.HZOJ270.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 22时37分24秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;
#define MAX_N 300000

int n, m, ans = INT32_MIN;
int num[MAX_N + 5];
int q[MAX_N + 5], head, tail;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        num[i] += num[i - 1];
    }
    q[tail++] = 0;
    ans = num[1];
    for (int i = 1; i <= n; i++) {
        if (q[head] < i - m) head++;
        ans = max(ans, num[i] - num[q[head]]);
        while (tail - head && num[q[tail - 1]] > num[i]) tail--;
        q[tail++] = i;
    }
    cout << ans << endl;
    return 0;
}
