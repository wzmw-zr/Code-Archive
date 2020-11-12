/*************************************************************************
	> File Name: 1.LeetCode1267.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月12日 星期四 09时40分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

int countServers(vector<vector<int>>& grid) {
    unordered_map<int, vector<PII>> row, column;
    set<PII> st;
    int h = grid.size(), w = grid[0].size();
    for (int i = 0; i < h; i++) row[i] = vector<PII>(0);
    for (int i = 0; i < w; i++) column[i] = vector<PII>(0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!grid[i][j]) continue;
            row[i].push_back(PII(i, j));
            column[j].push_back(PII(i, j));
        }
    }
    for (auto &x : row) {
        if (x.second.size() <= 1) continue;
        for (auto &y : x.second) st.insert(y);
    }
    for (auto &x : column) {
        if (x.second.size() <= 1) continue;
        for (auto &y : x.second) st.insert(y);
    }
    return st.size();
}

int main() {
    return 0;
}
