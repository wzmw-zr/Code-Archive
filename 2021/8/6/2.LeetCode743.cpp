/*************************************************************************
	> File Name: 2.LeetCode743.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月06日 星期五 15时48分54秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    int dis[n + 1];
    memset(dis, 0x3f, sizeof(dis));
    dis[k] = 0;
    for (int i = 1; i < n; i++) {
        for (auto t : times) dis[t[1]] = min(dis[t[1]], dis[t[0]] + t[2]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dis[i]);
    return ans == 0x3f3f3f3f ? -1 : ans;
}

int main() {
    return 0;
}
