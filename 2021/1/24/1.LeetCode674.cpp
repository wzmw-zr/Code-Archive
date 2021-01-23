/*************************************************************************
	> File Name: 1.LeetCode674.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月24日 星期日 00时01分49秒
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

int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;
    int left = 0, right = 1, ans = 1;
    while (right < n) {
        if (nums[right] > nums[right - 1]) ans = max(ans, right - left + 1);
        else left = right;
        right++;
    }
    return ans;
}

int main() {
    return 0;
}
