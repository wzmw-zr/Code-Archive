/*************************************************************************
	> File Name: 1.fft_recursive.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月09日 星期二 09时06分31秒
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
#include <cstring>
#include <cstdlib>
#include <complex>
using namespace std;

typedef complex<double> Comp;

Comp pi = acos(-1);

void fft(Comp *co, int k, int mode) {
    if (k == 1) return ;
    Comp temp[k];
    for (int i = 0; i < k; i++) {
        if (i & 1) temp[i / 2 + k / 2] = co[i];
        else temp[i / 2] = co[i];
    }
    for (int i = 0; i < k; i++) co[i] = temp[i];
    Comp *f = co, *g = co + k / 2;
    fft(f, k / 2, mode);
    fft(g, k / 2, mode);
    Comp w(1, 0), step = exp(((2.0 * mode / k) * pi) * Comp(0, 1));
    for (int i = 0; i < k / 2; i++) {
        temp[i] = f[i] + w * g[i];
        temp[i + k / 2] = f[i] - w * g[i];
        w *= step;
    }
    for (int i = 0; i < k; i++) co[i] = temp[i];
}

void solve() {
    int n;
    cin >> n;
    int t = __builtin_popcount(n) == 1 ? n : 1 << (32 - __builtin_clz(n));
    Comp *co = new Comp[t];
    for (int i = 0; i < n; i++) cin >> co[i];
    for (int i = 0; i < t; i++) cout << co[i] << " ";
    cout << endl;
    fft(co, t, 1);
    cout << "DFT" << endl;
    for (int i = 0; i < t; i++) cout << co[i] << " ";
    cout << endl;
    fft(co, t, -1);
    cout << "IDFT" << endl;
    for (int i = 0; i < t; i++) cout << co[i] / (t * 1.0) << " ";
    cout << endl;
}

int main() {
    solve();
    return 0;
}
