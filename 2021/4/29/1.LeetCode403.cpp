/*************************************************************************
	> File Name: 1.LeetCode403.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月29日 星期四 00时03分50秒
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

typedef pair<int, int> PII;

map<PII, bool> mp;

bool canCross(unordered_set<int> &stones, int pos, int step, int &mmax) {
    if (!stones.count(pos)) return false; 
    if (pos == mmax) return true;
    PII temp = PII(pos, step);
    if (mp.count(temp)) return mp[temp];
    bool ans = false;
    for (int i = max(1, step - 1); i <= step + 1 && !ans; i++) ans |= canCross(stones, pos + i, i, mmax);
    return mp[temp] = ans;
}

bool canCross(vector<int>& stones) {
    unordered_set<int> st;
    int mmax = *stones.rbegin();
    for (int x : stones) st.insert(x);
    return canCross(st, stones[0], 0, mmax);
}

int main() {
    return 0;
}
