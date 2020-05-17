/*************************************************************************
	> File Name: 4.HZOJ245.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月17日 星期日 19时22分21秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int n, pos, ans;
int num[MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    pos = num[n >> 1];
    for (int i = 0; i < n; i++) ans += abs(num[i] - pos);
    cout << ans << endl;
    return 0;
}
