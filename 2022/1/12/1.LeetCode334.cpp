/*************************************************************************
	> File Name: 1.LeetCode334.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月12日 星期三 09时15分31秒
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

bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 0);
    vector<int> suf(n, n - 1);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[*st.rbegin()] >= nums[i]) st.pop_back();
        st.push_back(i);
        pre[i] = st[0];
    }
    while (!st.empty()) st.pop_back();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[*st.rbegin()] <= nums[i]) st.pop_back();
        st.push_back(i);
        suf[i] = st[0];
    }
    for (int i = 0; i < n; i++) {
        if (pre[i] == i || suf[i] == i) continue;
        return true;
    }
    return false;
}

int main() {
    return 0;
}
