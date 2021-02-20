/*************************************************************************
	> File Name: 3.LeetCode1438.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月21日 星期日 00时58分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size(), l = 0, r = 0, len = 0;
    deque<int> min_st, max_st;
    while (r < n) {
        while (!min_st.empty() && nums[min_st.back()] > nums[r]) min_st.pop_back();
        min_st.push_back(r);
        while (!max_st.empty() && nums[max_st.back()] < nums[r]) max_st.pop_back();
        max_st.push_back(r);
        while (nums[max_st.front()] - nums[min_st.front()] > limit) {
            if (min_st.front() == l) min_st.pop_front();
            if (max_st.front() == l) max_st.pop_front();
            l++;
        }
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

int main() {
    return 0;
}
