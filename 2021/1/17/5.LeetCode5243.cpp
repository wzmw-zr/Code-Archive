/*************************************************************************
	> File Name: 5.LeetCode5243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月17日 星期日 14时47分48秒
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

int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> cnt;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) cnt[nums[i] * nums[j]]++;
    }
    int ans = 0;
    for (auto &&[x, y] : cnt) {
        if (y == 1) continue;
        ans += y * (y - 1) * 4;
    }
    return ans;
}

int main() {
    return 0;
}
