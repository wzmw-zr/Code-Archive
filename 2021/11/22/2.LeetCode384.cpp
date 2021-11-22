/*************************************************************************
	> File Name: 2.LeetCode384.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月22日 星期一 09时33分04秒
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

class Solution {
public:
    vector<int> nums;
    vector<int> original;

    Solution(vector<int>& nums) : nums(nums), original(nums) {}

    vector<int> reset() {
        return nums = original;
    }

    vector<int> shuffle() {
        int n = nums.size();
        for (int i = 0; i < n; i++) swap(nums[i], nums[i + rand() % (n - i)]);
        return nums;
    }
};

int main() {
    return 0;
}
