/*************************************************************************
	> File Name: 2.LeetCode1846.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月11日 星期四 08时56分46秒
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

typedef pair<int, int> PII;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size(), l = 0, r = 0;
    vector<int> ans;
    set<PII> st;
    while (r < k - 1)  st.insert(PII(nums[r], r)), r++;
    while (r < n) {
        st.insert(PII(nums[r], r));
        ans.push_back(st.rbegin()->first);
        st.erase(PII(nums[l], l));
        l++, r++;
    }
    return ans;
}

int main() {
    return 0;
}
