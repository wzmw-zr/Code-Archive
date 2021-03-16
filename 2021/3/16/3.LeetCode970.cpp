/*************************************************************************
	> File Name: 3.LeetCode970.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月16日 星期二 13时50分04秒
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
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound) {
    if (bound <= 1) return vector<int>(0);
    vector<int> x_pow({1});
    vector<int> y_pow({1});
    if (x != 1)
        while (x * *x_pow.rbegin() <= bound) 
            x_pow.push_back(x * *x_pow.rbegin());
    if (y != 1)
        while (y * *y_pow.rbegin() <= bound) 
            y_pow.push_back(y * *y_pow.rbegin());
    unordered_set<int> st;
    for (auto &a : x_pow) {
        for (auto &b : y_pow) {
            if (a + b <= bound) st.insert(a + b);
        }
    }
    vector<int> ans;
    for (auto a : st) ans.push_back(a);
    return ans;
}

int main() {
    int x, y, bound;
    cin >> x >> y >> bound;
    auto ans = powerfulIntegers(x, y, bound);
    for (auto a : ans) cout << a << " ";
    cout << endl;
    return 0;
}
