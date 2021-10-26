/*************************************************************************
	> File Name: 1.LeetCode496.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月26日 星期二 08时16分18秒
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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    stack<int> st;
    unordered_map<int, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums2[st.top()] < nums2[i]) st.pop();
        if (st.empty()) mp[nums2[i]] = -1;
        else mp[nums2[i]] = nums2[st.top()];
        st.push(i);
    }
    int m = nums1.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) ans[i] = mp[nums1[i]];
    return ans;
}

int main() {
    return 0;
}
