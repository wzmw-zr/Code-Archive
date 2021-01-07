/*************************************************************************
	> File Name: 1.LeetCode189.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 00时08分28秒
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

void shift_right(vector<int> &nums) {
    for (int i = nums.size() - 2; i >= 0; i--) swap(nums[i], nums[i + 1]);
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    while (k--) shift_right(nums);
}

int main() {
    return 0;
}
