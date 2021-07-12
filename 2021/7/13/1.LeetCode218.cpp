/*************************************************************************
	> File Name: 1.LeetCode218.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月13日 星期二 00时18分32秒
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

// TLE
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    set<int> points;
    for (auto &building : buildings) {
        points.insert(building[0]);
        points.insert(building[1]);
    }
    int ind = 1;
    unordered_map<int, int> mp_1, mp_2;
    for (int x : points) {
        mp_1[x] = ind;
        mp_2[ind] = x;
        ind++;
    }
    vector<int> heights((int) points.size() + 2, 0);
    for (auto &building : buildings) {
        for (int i = mp_1[building[0]]; i < mp_1[building[1]]; i++) heights[i] = max(heights[i], building[2]);
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= (int) points.size(); i++) {
        if ((heights[i] != heights[i - 1])) ans.push_back({mp_2[i], heights[i]});
    }
    return ans;
}

int main() {
    return 0;
}
