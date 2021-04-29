/*************************************************************************
	> File Name: 2.LeetCode862.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月30日 星期五 01时09分49秒
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

int shortestSubarray(vector<int>& A, int K) {
    int n = A.size();
    vector<long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (long) A[i];
    deque<int> que;
    int ans = INT32_MAX;
    for (int i = 0; i <= n; i++) {
        while (!que.empty() && pre[que.back()] > pre[i]) que.pop_back();
        while (!que.empty() && pre[que.front()] + K <= pre[i]) {
            ans = min(ans, i - que.front());
            que.pop_front();
        }
        que.push_back(i);
    }
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    return 0;
}
