/*************************************************************************
	> File Name: 1.LeetCode913.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月04日 星期二 21时32分53秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using TIII = tuple<int, int, int>;

int dfs(vector<vector<int>> &graph, int x, int y, int turn, map<TIII, int> &mp) {
    if (x == 0) return 1;
    if (x == y) return 2;
    if (turn >= 2 * graph.size()) return 0;
    TIII state(x, y, turn);
    if (mp.count(state)) return mp[state];
    if (turn & 1) {
        int flag = 1;
        for (int t : graph[y]) {
            if (!t) continue;
            int temp = dfs(graph, x, t, turn + 1, mp);
            if (temp == 2) {
                flag = 2;
                break;
            }
            if (temp == 0) flag = temp;
        }
        mp[state] = flag;
    } else {
        int flag = 2;
        for (int t : graph[x]) {
            int temp = dfs(graph, t, y, turn + 1, mp);
            if (temp == 1) {
                flag = 1;
                break;
            }
            if (temp == 0) flag = temp;
        }
        mp[state] = flag;
    }
    return mp[state];
}

int catMouseGame(vector<vector<int>>& graph) {
    map<TIII, int> mp;
    return dfs(graph, 1, 2, 0, mp);
}

int main() {
    return 0;
}
