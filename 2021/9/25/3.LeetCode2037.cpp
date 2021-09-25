/*************************************************************************
	> File Name: 3.LeetCode2037.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月25日 星期六 21时21分23秒
 ************************************************************************/

#include <iostream>
using namespace std;

int C(int n, int x) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    for (int i = 1; i <= x; i++) ans /= i;
    for (int i = 1; i <= n - x; i++) ans /= i;
    return ans;
}

int paintingPlan(int n, int k) {
    int ans = 0;
    if (n * n == k) return 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if ((i + j) * n - i * j != k) continue;
            ans += C(n, i) * C(n, j);
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << paintingPlan(n, k) << endl;
    return 0;
}
