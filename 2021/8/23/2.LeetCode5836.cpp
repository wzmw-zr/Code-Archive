/*************************************************************************
	> File Name: 2.LeetCode5836.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月23日 星期一 08时50分42秒
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

using ll = long long;
using PLI = pair<ll, int>;
const ll MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<PLI>> graph(n, vector<PLI>(0));
    for (auto r : roads) {
        graph[r[0]].push_back(PLI(r[2], r[1]));
        graph[r[1]].push_back(PLI(r[2], r[0]));
    }
    vector<ll> min_dis(n, INT64_MAX), cnts(n, 0);
    min_dis[0] = 0, cnts[0] = 1;
    set<PLI> st;
    st.insert(PLI(0, 0));
    while (!st.empty()) {
        auto [dis, ind] = *st.begin();
        st.erase(st.begin());
        if (dis > min_dis[ind]) continue;
        min_dis[ind] = dis;
        for (auto [n_len, n_ind] : graph[ind]) {
            if (min_dis[n_ind] >= dis || min_dis[n_ind] + n_len > dis) continue;
            cnts[ind] += cnts[n_ind];
        }
        cnts[ind] %= MOD;
        if (ind == (n - 1)) break;
        for (auto [n_len, n_ind] : graph[ind]) st.insert(PLI(dis + n_len, n_ind));
    }
    return cnts[n - 1];
}

int main() {
    return 0;
}
