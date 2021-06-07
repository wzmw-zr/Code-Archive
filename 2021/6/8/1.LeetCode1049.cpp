/*************************************************************************
	> File Name: 1.LeetCode1049.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 00时07分42秒
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

map<vector<int>, int> st;

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    if (n == 0) return 0;
    if (n == 1) return stones[0];
    if (st.count(stones)) return st[stones];
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> temp;
            for (int k = 0; k < n; k++) {
                if ((k == i) || (k == j)) continue;
                temp.push_back(stones[k]);
            }
            if (stones[i] - stones[j]) {
                temp.push_back(abs(stones[j] - stones[i]));
                sort(temp.begin(), temp.end());
            }
            ans = min(ans, lastStoneWeightII(temp));
        }
    }
    return st[stones] = ans;
}

int main() {
    return 0;
}
