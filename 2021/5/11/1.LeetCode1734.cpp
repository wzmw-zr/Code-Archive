/*************************************************************************
	> File Name: 1.LeetCode1734.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月11日 星期二 00时31分23秒
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

vector<int> decode(vector<int>& encoded) {
    int n = encoded.size() + 1;
    int xor_sum = 0;
    for (int i = 1; i <= n; i++)
        xor_sum ^= i;
    for (int i = 1; i < n - 1; i += 2) 
        xor_sum ^= encoded[i];
    vector<int> ans(n, 0);
    ans[0] = xor_sum;
    for (int i = 0; i < n - 1; i++) {
        xor_sum ^= encoded[i];
        ans[i + 1] = xor_sum;
    }
    return ans;
}

int main() {
    return 0;
}
