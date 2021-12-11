/*************************************************************************
	> File Name: 3.LeetCode5934.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月11日 星期六 22时31分30秒
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

vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<int> que;
    multiset<int> st;
    for (int x : nums) que.push(x);
    while (k--) {
        st.insert(que.top());
        que.pop();
    }
    vector<int> ans;
    for (int x : nums) {
        if (!st.count(x)) continue;
        ans.push_back(x);
        st.erase(st.find(x));
    }
    return ans;
}

int main() {
    return 0;
}
