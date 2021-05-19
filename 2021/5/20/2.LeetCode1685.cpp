/*************************************************************************
	> File Name: 2.LeetCode1685.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月20日 星期四 00时14分47秒
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

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    int pre = 0;
    vector<int> ans(n);
    for (int x : nums) sum += x;
    for (int i = 0; i < n; i++) {
        pre += nums[i];
        int rest = sum - pre;
        ans[i] = nums[i] * (i + 1) - pre + rest - nums[i] * (n - i - 1);
    }
    return ans;
}

int main() {
    return 0;
}
