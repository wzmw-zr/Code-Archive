/*************************************************************************
	> File Name: 2.LeetCode189.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 00时19分36秒
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

void interval_reverse(vector<int> &nums, int left, int right) {
    for (int i = left, j = right; i < j; i++, j--) swap(nums[i], nums[j]);
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    interval_reverse(nums, 0, n - 1);
    interval_reverse(nums, 0, k - 1);
    interval_reverse(nums, k, n - 1);
}

int main() {
    return 0;
}
