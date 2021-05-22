/*************************************************************************
	> File Name: 1.LeetCode1707.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月23日 星期日 00时05分08秒
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

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int q = queries.size();
    vector<int> ans(q, -1);
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n && nums[j] <= queries[i][1]; j++) 
            ans[i] = max(ans[i], queries[i][0] ^ nums[j]);
    }
    return ans;
}

int main() {
    return 0;
}
