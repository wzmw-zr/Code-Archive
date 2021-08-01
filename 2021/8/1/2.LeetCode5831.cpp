/*************************************************************************
	> File Name: 2.LeetCode5831.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月01日 星期日 10时35分17秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long numberOfWeeks(vector<int>& milestones) {
    int n = milestones.size();
    long long sum = 0;
    long long ans = 0;
    priority_queue<int> que;
    sort(milestones.begin(), milestones.end());
    for (int x : milestones) {
        sum += static_cast<long long>(x);
        que.push(x);
    }
    while (que.size() >= 2) {
        int x = que.top();
        que.pop();
        int y = que.top();
        que.pop();
        ans += static_cast<long long>(y) * static_cast<long long>(2);
        if (x != y) que.push(x - y);
    }
    if (sum <= static_cast<long long>(milestones[n - 1]) * static_cast<long long>(2)) { 
        ans += que.empty() ? 0 : 1;
    } else {
        ans += que.empty() ? 0 : que.top();
    }
    return ans;
}

int main() {
    return 0;
}
