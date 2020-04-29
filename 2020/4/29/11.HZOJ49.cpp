/*************************************************************************
	> File Name: 11.HZOJ49.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 20时00分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100000

int all, n, ind;
int w[MAX_N * MAX_N + 5], v[MAX_N * MAX_N + 5], s[MAX_N * MAX_N + 5];
int ans[MAX_V + 5];
int t[20];

int main() {
    int tt = 1;
    for (int i = 0; i < 20; i++) {
        t[i] = tt;
        tt *= 2;
    }
    cin >> all >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z, temp = 0;
        cin >> x >> y >> z;
        while (z > 0) {
            if (z >= t[temp]) {
                w[ind] = x * t[temp];
                v[ind] = y * t[temp];
                z -= t[temp];
            } else {
                w[ind] = x * z;
                v[ind] = y * z;
                z = 0;
            }
            ind++;
            temp++;
        }
    }
    for (int i = 0; i < ind; i++) {
        for (int j = all; j >= 0; j--) {
            if (j >= w[i]) ans[j] = max(ans[j], ans[j - w[i]] + v[i]); 
        }
    }
    cout << ans[all] << endl;
    return 0;
}

