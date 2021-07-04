/*************************************************************************
	> File Name: 2.LeetCode5801.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月04日 星期日 10时33分48秒
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
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(speed[i])) mp[speed[i]] = priority_queue<int, vector<int>, greater<int>>();
        mp[speed[i]].push(dist[i]);
    }
    int t = 0;
    int cnt = 0;
    while (cnt < n) {
        int dis = INT32_MAX, spd = INT32_MAX;
        for (auto &&[sp, que] : mp) { 
            if (que.empty()) continue;
            int d = que.top() - sp * t;
            if (d < dis) {
                dis = d;
                spd = sp;
            }
        }
        if (dis <= 0) break;
        mp[spd].pop();
        cnt++;
        t++;
    }
    return cnt;
}

int main() {
    return 0;
}
