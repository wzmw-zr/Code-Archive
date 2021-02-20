/*************************************************************************
	> File Name: 1.LeetCode1438.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月21日 星期日 00时01分25秒
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
    multiset<int> st;
    while (r < n) {
        st.insert(nums[r]);
        if (*st.rbegin() - *st.begin() > limit) {
            len = max(len, (int) st.size() - 1);
            while (*st.rbegin() - *st.begin() > limit) st.erase(st.find(nums[l++]));
        }
        r++;
    }
    len = max(len, (int) st.size());
    return len;
}

int main() {
    return 0;
}
