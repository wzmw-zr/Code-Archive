/*************************************************************************
	> File Name: 1.LeetCode503.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月06日 星期六 14时22分38秒
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

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nums2;
    for (int &x : nums) nums2.push_back(x);
    for (int &x : nums) nums2.push_back(x);
    vector<int> ans(n, -1);
    stack<int> right;
    for (int i = 0; i < 2 * n; i++) {
        while (!right.empty() && nums2[right.top()] < nums2[i]) {
            if (right.top() < n && i - right.top() < n)
                ans[right.top()] = nums2[i];
            right.pop();
        }
        right.push(i);
    }
    return ans;
}

int main() {
    return 0;
}
