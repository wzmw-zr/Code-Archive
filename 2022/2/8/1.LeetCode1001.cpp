/*************************************************************************
	> File Name: 1.LeetCode1001.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月08日 星期二 00时48分02秒
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
using MISP = unordered_map<int, set<PII>>;

void delete_pos(MISP &row, MISP &col, MISP &left_diagonal, MISP &right_diagonal, PII &pos) {
    if (row.count(pos.first)) {
        row[pos.first].erase(pos);
        if (row[pos.first].empty()) row.erase(pos.first);
    }
    if (col.count(pos.second)) {
        col[pos.second].erase(pos);
        if (col[pos.second].empty()) col.erase(pos.second);
    }
    if (left_diagonal.count(pos.first - pos.second)) {
        left_diagonal[pos.first - pos.second].erase(pos);
        if (left_diagonal[pos.first - pos.second].empty()) left_diagonal.erase(pos.first - pos.second);
    }
    if (right_diagonal.count(pos.first + pos.second)) {
        right_diagonal[pos.first + pos.second].erase(pos);
        if (right_diagonal[pos.first + pos.second].empty()) right_diagonal.erase(pos.first + pos.second);
    }
}

int dir[9][2] = {0, 0, 1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    unordered_map<int, set<PII>> row, col, left_diagonal, right_diagonal;
    for (auto &lamp : lamps) {
        if (!row.count(lamp[0])) {
            row[lamp[0]] = set<PII>();
        }
        row[lamp[0]].insert(PII(lamp[0], lamp[1]));
        if (!col.count(lamp[1])) {
            col[lamp[1]] = set<PII>();
        }
        col[lamp[1]].insert(PII(lamp[0], lamp[1]));
        if (!left_diagonal.count(lamp[0] - lamp[1])) {
            left_diagonal[lamp[0] - lamp[1]] = set<PII>();
        }
        left_diagonal[lamp[0] - lamp[1]].insert(PII(lamp[0], lamp[1]));
        if (!right_diagonal.count(lamp[0] + lamp[1])) {
            right_diagonal[lamp[0] + lamp[1]] = set<PII>();
        }
        right_diagonal[lamp[0] + lamp[1]].insert(PII(lamp[0], lamp[1]));
    }
    vector<int> res;
    res.reserve(queries.size());
    for (auto &q : queries) {
        int flag = 0;
        if (row.count(q[0]) || col.count(q[1]) || left_diagonal.count(q[0] - q[1]) || right_diagonal.count(q[0] + q[1])) {
            flag = 1;
        }
        for (int i = 0; i < 9; i++) {
            int x = q[0] + dir[i][0];
            int y = q[1] + dir[i][1];
            PII pos(x, y);
            delete_pos(row, col, left_diagonal, right_diagonal, pos);
        }
        res.push_back(flag);
    }
    return res;
}

int main() {
    return 0;
}
