/*************************************************************************
	> File Name: 1.LeetCode1655.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月07日 星期四 19时40分44秒
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

// WA
using PII = pair<int, int>;

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    priority_queue<PII> que;
    for (auto &&[x, cnt] : mp) que.push(PII(cnt, x));
    auto cmp = [](int a, int b) { return a > b; };
    sort(quantity.begin(), quantity.end(), cmp);
    for (int x : quantity) {
        if (que.empty() || que.top().first < x) return false;
        auto temp = que.top();
        que.pop();
        temp.first -= x;
        if (temp.first) que.push(temp);
    }
    return true;
}

int main() {
    return 0;
}
