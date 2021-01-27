/*************************************************************************
	> File Name: 1.LeetCode724.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月28日 星期四 00时01分46秒
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

int pivotIndex(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for (int &x : nums) sum += x;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (pre == (sum - pre - nums[i])) return i;
        pre += nums[i];
    }
    return -1;
}

int main() {
    return 0;
}
