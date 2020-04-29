/*************************************************************************
	> File Name: 10.HZOJ49.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 19时41分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100000

int v, n;
int w[MAX_N + 5], val[MAX_N + 5], s[MAX_N + 5];
int ans[MAX_V + 5];

int main() {
    cin >> v >> n;
    for (int i = 0; i < n; i++) cin >> w[i] >> val[i] >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = v; j >= 0; j--) {
            for (int k = 0; k <= s[i]; k++) {
                if (j < k * w[i]) break;
                ans[j] = max(ans[j], ans[j - k * w[i]] + k * val[i]);
            }
        }
    }
    cout << ans[v] << endl;
    return 0;
}
