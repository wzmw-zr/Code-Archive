/*************************************************************************
	> File Name: 2.LeetCode883.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月19日 星期五 00时11分48秒
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

int projectionArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = 0;
    vector<vector<int>> rows(n, vector<int>(0));
    vector<vector<int>> cols(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rows[i].push_back(grid[i][j]);
            cols[j].push_back(grid[i][j]);
            ans += grid[i][j] ? 1 : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        sort(rows[i].begin(), rows[i].end());   
        ans += *rows[i].rbegin();
    }
    for (int i = 0; i < n; i++) {
        sort(cols[i].begin(), cols[i].end());
        ans += *cols[i].rbegin();
    }
    return ans;
}

int main() {
    return 0;
}
