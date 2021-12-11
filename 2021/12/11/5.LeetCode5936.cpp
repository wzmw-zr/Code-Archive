/*************************************************************************
	> File Name: 5.LeetCode5936.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月11日 星期六 22时54分44秒
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

int bfs(vector<vector<long>> &bombs, int ind) {
    int n = bombs.size();
    vector<int> check(n, 0);
    queue<int> que;
    que.push(ind);
    int cnt = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        if (check[temp]) continue;
        cnt++;
        check[temp] = 1;
        for (int i = 0; i < n; i++) {
            if (check[i]) continue;
            long x_t = abs(bombs[temp][0] - bombs[i][0]);
            long y_t = abs(bombs[temp][1] - bombs[i][1]);
            if ((x_t * x_t + y_t * y_t) <= bombs[temp][2] * bombs[temp][2]) que.push(i);
        }
    }
    return cnt;
}

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    int ans = 0;
    vector<vector<long>> new_bombs;
    for (auto bomb : bombs) {
        vector<long> temp;
        for (auto x : bomb) temp.push_back(x);
        new_bombs.push_back(temp);
    }
    for (int i = 0; i < n; i++) ans = max(bfs(new_bombs, i), ans);
    return ans;
}

int main() {
    return 0;
}
