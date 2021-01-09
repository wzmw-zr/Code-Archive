/*************************************************************************
	> File Name: 1.LeetCode228.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月10日 星期日 00时04分31秒
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

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int left = 0, right = 1, n = nums.size();
    while (right < n) {
        if (nums[right] - nums[right - 1] == 1) right++;
        else {
            if (left == (right - 1)) ans.push_back(to_string(nums[left]));
            else ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
            left = right++;
        }
    }
    if (left == (right - 1)) ans.push_back(to_string(nums[left]));
    else ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
    return ans;
}

int main() {
    return 0;
}
