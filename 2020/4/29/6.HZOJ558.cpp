/*************************************************************************
	> File Name: 6.HZOJ558.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 18时07分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_M 100
#define MAX_T 1000

int t, m;
int Time[MAX_M + 5], val[MAX_M + 5];
int f[MAX_T + 5];

int main() {
    cin >> t >> m;
    for (int i = 0; i < m; i++) cin >> Time[i] >> val[i];
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= 0; j--) {
            if (j >= Time[i]) f[j] = max(f[j], f[j - Time[i]] + val[i]);
        }
    }
    cout << f[t] << endl;
    return 0;
}
