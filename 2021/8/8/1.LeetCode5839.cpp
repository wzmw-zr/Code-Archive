/*************************************************************************
	> File Name: 1.LeetCode5839.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月08日 星期日 10时49分21秒
 ************************************************************************/

#include <iostream>
#include <cmath>
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

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> que;
    for (int x : piles) que.push(x);
    while (!que.empty() && k) {
        int t = que.top();
        que.pop();
        que.push(t - t / 2);
        k--;
    }
    int ans = 0;
    while (!que.empty()) {
        ans += que.top();
        que.pop();
    }
    return ans;
}

int main() {
    return 0;
}
