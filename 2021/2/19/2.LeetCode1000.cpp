/*************************************************************************
	> File Name: 2.LeetCode1000.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月19日 星期五 11时03分25秒
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

// WA
typedef pair<bool, vector<int>> PBI;

PBI merge(vector<int> &stones, int &K) {
    if (stones.size() < K) return PBI(false, vector<int>(0));
    PBI ans = PBI(true, vector<int>(3, INT32_MAX));
    int n = stones.size(), l = 0, r = 0, sum = 0;
    while (r < K - 1) sum += stones[r++];
    while (r < n) {
        sum += stones[r];
        if (sum < ans.second[0]) ans.second[0] = sum, ans.second[1] = l, ans.second[2] = r;
        sum -= stones[l];
        l++, r++;
    }
    return ans;
}
    
int mergeStones(vector<int>& stones, int K) {
    int ans = 0;
    while (stones.size() > 1) {
        auto &&[state, info] = merge(stones, K);
        if (!state) return -1;
        ans += info[0];
        vector<int> temp = vector<int>(0);
        for (int i = 0; i < info[1]; i++) temp.push_back(stones[i]);
        temp.push_back(info[0]);
        for (int i = info[2] + 1; i < stones.size(); i++) temp.push_back(stones[i]);
        stones = temp;
    }
    return ans;
}

int main() {
    return 0;
}
