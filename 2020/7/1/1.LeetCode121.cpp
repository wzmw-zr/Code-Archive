/*************************************************************************
	> File Name: 1.LeetCode121.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月01日 星期三 07时11分02秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

int maxProfit(vector<int> &prices) {
    int p_len = prices.size();
    if (p_len == 0) return 0;
    int mmax = prices[p_len - 1], res = 0;
    for (int i = p_len - 2; i >= 0; i--) {
        mmax = max(mmax, prices[i]);
        res = max(res, mmax - prices[i]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prices.push_back(x);
    }
    cout << maxProfit(prices) << endl;
    return 0;
}
