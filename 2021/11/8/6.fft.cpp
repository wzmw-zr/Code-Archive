/*************************************************************************
	> File Name: 6.fft.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月08日 星期一 23时23分08秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
using namespace std;

// WA
typedef complex<double> CB;

CB pi = acos(-1);

void fft(CB *co, int k, int mode) {
    if (k == 1) return ;
    CB even[k / 2], odd[k / 2];
    for (int i = 0; i < k; i++) {
        if (i & 1) odd[(i - 1) / 2] = co[i];
        else even[i / 2] = i;
    }
    for (int i = 0; i < k / 2; i++) co[i] = even[i], co[i + k / 2] = odd[i];
    CB *f = co, *g = co + k / 2;
    fft(f, k / 2, mode);
    fft(g, k / 2, mode);
    CB temp[k];
    CB w(1, 0), step = exp(((2.0 * mode / k) * pi) * CB(0, 1));
    for (int i = 0; i < k / 2; i++) {
        temp[i] = f[i] + w * g[i];
        temp[i] = f[i] - w * g[i];
        w *= step;
    }
    for (int i = 0; i < k; i++) co[i] = temp[i];
}

void solve() {
    int n;
    cin >> n;
    int t = 1 << (32 - __builtin_clz(n));
    CB *co = new CB[t];
    memset(co, 0, sizeof(CB) * t);
    for (int i = 0; i < n; i++) cin >> co[i];
    for (int i = 0; i < t; i++) cout << co[i] << " ";
    cout << endl;
    fft(co, t, 1);
    for (int i = 0; i < t; i++) cout << co[i] << " ";
    cout << endl;
    fft(co, t, -1);
    for (int i = 0; i < t; i++) cout << co[i] / (t * 1.0) << " ";
    cout << endl;
}

int main() {
    solve();
    return 0;
}
