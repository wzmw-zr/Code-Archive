/*************************************************************************
	> File Name: 1.LeetCode407.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月03日 星期三 10时55分24秒
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
int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    vector<vector<int>> left(m, vector<int>(n));
    vector<vector<int>> right(m, vector<int>(n));
    vector<vector<int>> top(m, vector<int>(n));
    vector<vector<int>> down(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        vector<int> st;
        for (int j = 0; j < n; j++) {
            while (!st.empty() && heightMap[i][*st.rbegin()] <= heightMap[i][j]) st.pop_back();
            if (st.empty()) left[i][j] = heightMap[i][j];
            else left[i][j] = heightMap[i][st[0]];
            st.push_back(j);
        }
    }

    for (int i = 0; i < m; i++) {
        vector<int> st;
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && heightMap[i][*st.rbegin()] <= heightMap[i][j]) st.pop_back();
            if (st.empty()) right[i][j] = heightMap[i][j];
            else right[i][j] = heightMap[i][st[0]];
            st.push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> st;
        for (int j = 0; j < m; j++) {
            while (!st.empty() && heightMap[*st.rbegin()][i] <= heightMap[j][i]) st.pop_back();
            if (st.empty()) top[j][i] = heightMap[j][i];
            else top[j][i] = heightMap[st[0]][i];
            st.push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> st;
        for (int j = m - 1; j >= 0; j--) {
            while (!st.empty() && heightMap[*st.rbegin()][i] <= heightMap[j][i]) st.pop_back();
            if (st.empty()) down[j][i] = heightMap[j][i];
            else down[j][i] = heightMap[st[0]][i];
            st.push_back(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans += max(0, min({left[i][j], right[i][j], top[i][j], down[i][j]}) - heightMap[i][j]);
        }
    }

    return ans;
}

int main() {
    return 0;
}
