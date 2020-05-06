/*************************************************************************
	> File Name: 2.HZOJ343.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月04日 星期一 15时26分20秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;
#define MAX_N 3000

int n, ans, max_len;
int a[MAX_N + 5], b[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int len_to_num[MAX_N + 5];
int len_to_a_ind[MAX_N + 5], len_to_b_ind[MAX_N + 5];


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i <= n; i++) len_to_num[i] = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        int tmp = max_len;
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                cout << "a[" << i << "] = " << a[i];
                cout << ", b[" << j << "] = " << b[j];
                cout << endl;
                for (int k = tmp; k >= 0; k--) {
                    cout << "len_to_num[" << k << "] = " << len_to_num[k];
                    cout << ", len_to_a_ind[" << k << "] = " << len_to_a_ind[k];
                    cout << ", len_to_b_ind[" << k << "] = " << len_to_b_ind[k];
                    cout << endl << endl;
                    if (len_to_num[k] < a[i] && len_to_a_ind[k] < i && len_to_b_ind[k] < j) {
                        max_len = max(max_len, k + 1);
                        if (len_to_num[k + 1] == INT32_MIN || len_to_num[k + 1] > a[i]) {
                            len_to_num[k + 1] = a[i];
                            len_to_a_ind[k + 1] = i;
                            len_to_b_ind[k + 1] = j;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << max_len << endl;
    return 0;
}
