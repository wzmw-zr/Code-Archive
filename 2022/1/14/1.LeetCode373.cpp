/*************************************************************************
	> File Name: 1.LeetCode373.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月14日 星期五 09时35分27秒
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

using PII = pair<int, int>;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto cmp = [&](PII &a, PII &b) -> bool {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    vector<vector<int>> ans;
    priority_queue<PII, vector<PII>, decltype(cmp)> que(cmp);
    int n = nums1.size(), m = nums2.size();
    for (int i = 0; i < n; i++) que.push(PII(i, 0));
    while (!que.empty() && ans.size() < k) {
        auto temp = que.top();
        que.pop();
        ans.push_back({nums1[temp.first], nums2[temp.second]});
        if (temp.second + 1 < m) que.push(PII(temp.first, temp.second + 1));
    }
    return ans;
}

int main() {
    return 0;
}
