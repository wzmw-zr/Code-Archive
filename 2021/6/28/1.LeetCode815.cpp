/*************************************************************************
	> File Name: 1.LeetCode815.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月28日 星期一 10时57分57秒
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

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    int n = routes.size();
    unordered_map<int, vector<int>> station;
    for (int i = 0; i < n; i++) {
        for (int x : routes[i]) {
            if (!station.count(x)) station[x] = vector<int>(0);
            station[x].push_back(i);
        }
    }
    unordered_map<int, int> mp;
    queue<int> que;
    mp[source] = 0;
    que.push(source);
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        if (temp == target) return mp[temp];
        for (int r : station[temp]) {
            for (int s : routes[r]) {
                if (mp.count(s)) continue;
                mp[s] = mp[temp] + 1;
                que.push(s);
            }
        }
    }
    return -1;
}

int main() {
    return 0;
}
