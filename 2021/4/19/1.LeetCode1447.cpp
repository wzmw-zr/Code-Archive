/*************************************************************************
	> File Name: 1.LeetCode1447.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月19日 星期一 21时50分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

vector<string> simplifiedFractions(int n) {
    vector<string> ans;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(i, j) > 1) continue;
            ans.push_back(to_string(j) + "/" + to_string(i));
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    auto ans = simplifiedFractions(n);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
