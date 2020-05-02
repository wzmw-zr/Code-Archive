/*************************************************************************
	> File Name: 4.HZOJ343.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月02日 星期六 22时50分40秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cinttypes>
using namespace std;
#define MAX_N 3000

long n;
long a[MAX_N + 5], b[MAX_N + 5];
//long dp[MAX_N + 5][MAX_N + 5];
long len_to_num[MAX_N + 5];
long len_to_ind[MAX_N + 5];
long max_len;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i <= n; i++) len_to_num[i] = INT64_MIN;
    for (long i = 1; i <= n; i++) {
        int tmp_len = max_len;
        for (long j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                for (long k = tmp_len; k >= 0; k--) {
                    if (len_to_num[k] < a[i]) {
                        cout << "k = " << k << ", len_to_num[k] = " << len_to_num;
                        cout << ", i = " << i << ", j = " << j << ", a[i] = " << a[i] << endl;
                        if (len_to_ind[k] < j) {
                            max_len = max(max_len, k + 1);
                            if (len_to_num[k + 1] == INT64_MIN || len_to_num[k + 1] > a[i]) {
                                len_to_num[k + 1] = a[i];
                                len_to_ind[k + 1] = j;
                            } 
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << max_len << endl;
    return 0;
}
