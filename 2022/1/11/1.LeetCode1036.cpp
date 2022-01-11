/*************************************************************************
	> File Name: 1.LeetCode1036.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月11日 星期二 09时36分28秒
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

using PII = pair<int, int>;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    int n = blocked.size();
    queue<PII> que;
    que.push(PII(source[0], source[1]));
    set<PII> blocks;
    for (auto block : blocked) blocks.insert(PII(block[0], block[1]));
    set<PII> st;
    st.insert(PII(source[0], source[1]));
    while (!que.empty()) {
        auto temp = que.front();
        if (temp.first == target[0] && temp.second == target[1]) return true;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.first + dir[i][0];
            int y = temp.second + dir[i][1];
            PII pos(x, y);
            if (x < 0 || x >= 1e6 || y < 0 || y >= 1e6 || blocks.count(pos) || st.count(pos)) continue;
            que.push(pos);
            st.insert(pos);
        }
        if (st.size() > n * (n - 1) / 2) break;
    }
    if (st.size() <= n * (n - 1) / 2) return false;

    st.clear();
    while (!que.empty()) que.pop();

    que.push(PII(target[0], target[1]));
    st.insert(PII(target[0], target[1]));
    while (!que.empty()) {
        auto temp = que.front();
        if (temp.first == source[0] && temp.second == source[1]) return true;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.first + dir[i][0];
            int y = temp.second + dir[i][1];
            PII pos(x, y);
            if (x < 0 || x >= 1e6 || y < 0 || y >= 1e6 || blocks.count(pos) || st.count(pos)) continue;
            que.push(pos);
            st.insert(pos);
        }
        if (st.size() > n * (n - 1) / 2) break;
    }
    if (st.size() <= n * (n - 1) / 2) return false;
    return true;
}

int main() {
    return 0;
}
