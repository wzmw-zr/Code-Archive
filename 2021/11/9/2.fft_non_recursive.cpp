/*************************************************************************
	> File Name: 2.fft_non_recursive.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月09日 星期二 09时38分17秒
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

const double pi = acos(-1);

void fft(Comp *co, int k, int mode) {
    int pos[k];
    Comp temp[k];
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i < k; i++) pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? (k >> 1) : 0);
    for (int i = 0; i < k; i++) temp[pos[i]] = co[i];
    for (int l = 2; l <= k; l <<= 1) {
        for (int i = 0; i < k; i += l) {
            Comp res[l];
            Comp w(1, 0), step(cos(2.0 * mode / l * pi), sin(2.0 * mode / l * pi));
            for (int j = 0; j < l / 2; j++) {
                res[j] = temp[i + j] + w * temp[i + l / 2 + j];
                res[j + l / 2] = temp[i + j] - w * temp[i + l / 2 + j];
                w *= step;
            }
            for (int j = 0; j < l; j++) temp[i + j] = res[j];
        }
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
