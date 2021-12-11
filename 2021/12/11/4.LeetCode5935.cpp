/*************************************************************************
	> File Name: 4.LeetCode5935.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月11日 星期六 22时36分56秒
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

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    vector<int> pre(n, 1), suf(n, 1);
    pre[0] = 0;
    suf[n - 1] = 0;
    for (int i = 1; i < n - 1; i++) {
        if (security[i] <= security[i - 1]) pre[i + 1] = pre[i] + 1;
    }
    for (int i = n - 2; i >= 1; i--) {
        if (security[i] <= security[i + 1]) suf[i - 1] = suf[i] + 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (pre[i] >= time && suf[i] >= time) {
            if (time == 0 || i == 0 || i == n - 1) {
                ans.push_back(i);
                continue;
            }
            if (security[i] <= security[i - 1] && security[i] <= security[i + 1]) ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    return 0;
}
