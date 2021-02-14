/*************************************************************************
	> File Name: 1.LeetCode485.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月15日 星期一 00时01分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, n = nums.size(), l = 0,  r = 0;
    while (r < n) {
        while (r < n && nums[r] == 0) r++;
        l = r;
        while (r < n && nums[r] == 1) r++;
        ans = max(ans, r - l);
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    return 0;
}
