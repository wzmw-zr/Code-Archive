/*************************************************************************
	> File Name: 1.LeetCode239.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月02日 星期六 00时01分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (!que.empty() && i - que.front() == k - 1) que.pop_front();
        while (!que.empty() && nums[i] > nums[que.back()]) que.pop_back();
        que.push_back(i);
        if (i >= k - 1) ans.push_back(nums[que.front()]);
    }
    return ans;
}

int main() {
    return 0;
}
