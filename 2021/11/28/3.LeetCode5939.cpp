/*************************************************************************
	> File Name: 3.LeetCode5939.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月28日 星期日 10时33分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
    vector<int> ans(n, -1);
    for (int i = k; i < n - k; i++) {
        ans[i] = (pre[i + k + 1] - pre[i - k]) / (2 * k + 1);
    }
    return ans;
}

int main() {
    return 0;
}
