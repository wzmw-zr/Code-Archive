/*************************************************************************
	> File Name: 1.fft.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月23日 星期六 14时23分11秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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
using namespace std;

using Comp = complex<double>;

void DFT(Comp *nums, int n, int mode) {
    if (n == 1) return ;
    Comp tmp[n];
    for (int i = 0; i < n; i++) tmp[i] = nums[i];
    for (int i = 0; i < n; i++) {
        if (i & 1) nums[(i - 1) / 2 + n / 2] = tmp[i];
        else nums[i / 2] = tmp[i];
    }
    Comp *h = nums, *g = nums + n / 2;
    DFT(h, n / 2, mode);
    DFT(g, n / 2, mode);
    double pi = acos(-1.0);
    Comp w = Comp(1, 0), step = exp(2.0 * pi * Comp(0, 1) / (1.0 * mode * n));
    for (int k = 0; k < n / 2; k++) {
        tmp[k] = h[k] + w * g[k];
        tmp[k + n / 2] = h[k] - w * g[k];
    }
    for (int i = 0; i < n; i++) nums[i] = tmp[i];
}

int main() {
    int n, total;
    cin >> n;
    if (__builtin_popcount(n) == 1) total = n;
    else total = (1 << (32 - __builtin_clz(n)));
    Comp *co = new Comp[total];
    for (int i = 0; i < n; i++) cin >> co[i];
    for (int i = 0; i < total; i++) cout << co[i] <<  " ";
    cout << endl;
    DFT(co, total, 1);
    for (int i = 0; i < total; i++) cout << co[i] <<  " ";
    cout << endl;
    DFT(co, total, -1);
    for (int i = 0; i < total; i++) cout << co[i] / (1.0 * total) <<  " ";
    cout << endl;
    #if 0
    cout << coefficients.size() << endl;
    for (int x : coefficients) cout << x << " ";
    cout << endl;
    #endif
    return 0;
}
