/*************************************************************************
	> File Name: 5.HZOJ44.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 19时21分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000

int n, mmax;
int num[MAX_N + 5];
int dp[MAX_N + 5], ans;
int len[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1; i <= n; i++) dp[i] = 1, len[i] = n + 1;
    len[++ans] = num[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, num[i]);
        len[dp[i]] = num[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
