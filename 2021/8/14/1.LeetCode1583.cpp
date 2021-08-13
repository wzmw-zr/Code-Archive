/*************************************************************************
	> File Name: 1.LeetCode1583.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月14日 星期六 00时04分05秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) mat[i][preferences[i][j]] = n - 1 - j;
    }
    int check[n];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n / 2; i++) {
        int x = pairs[i][0], y = pairs[i][1];
        for (int j = i + 1; j < n / 2; j++) {
            int u = pairs[j][0], v = pairs[j][1];
            if ((mat[x][u] > mat[x][y]) && (mat[u][x] > mat[u][v])) check[x] = check[u] = 1;
            if ((mat[x][v] > mat[x][y]) && (mat[v][x] > mat[v][u])) check[x] = check[v] = 1;
            if ((mat[y][u] > mat[y][x]) && (mat[u][y] > mat[u][v])) check[y] = check[u] = 1;
            if ((mat[y][v] > mat[y][x]) && (mat[v][y] > mat[v][u])) check[y] = check[v] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += check[i];
    return cnt;
}

int main() {
    return 0;
}
