/*************************************************************************
	> File Name: 3.LeetCode36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月17日 星期五 21时21分19秒
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

// misunderstanding the intend of the question, this method is to check whether the sudoku is solveable.
bool dfs(int line, int ind, int &n, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &girds, vector<vector<int>> &rests, vector<vector<int>> &empty);

bool is_valid_sudoku(int line, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &girds, vector<vector<int>> &rests, vector<vector<int>> &empty);

bool is_valid(int line, int column, int num, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids) {
    return !(rows[line][num] || cols[column][num] || grids[(line / 3) * 3 + column / 3][num]);
}

void mark(int line, int column, int num, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids) {
    rows[line][num] = 1;
    cols[column][num] = 1;
    grids[(line / 3) * 3 + column / 3][num] = 1;
}

void unmark(int line, int column, int num, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids) {
    rows[line][num] = 0;
    cols[column][num] = 0;
    grids[(line / 3) * 3 + column / 3][num] = 0;
}


bool dfs(int line, int ind, int &n, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids, vector<vector<int>> &rests, vector<vector<int>> &empty, vector<int> &check) {
    if (ind == n) return is_valid_sudoku(line + 1, rows, cols, grids, rests, empty);
    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        if (check[i] || !is_valid(line, empty[line][ind], rests[line][i], rows, cols, grids)) continue;
        check[i] = 1;
        mark(line, empty[line][ind], rests[line][i], rows, cols, grids);
        ans |= dfs(line, ind + 1, n, rows, cols, grids, rests, empty, check);
        unmark(line, empty[line][ind], rests[line][i], rows, cols, grids);
        check[i] = 0;
    }
    return ans;
}

bool is_valid_sudoku(int line, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids, vector<vector<int>> &rests, vector<vector<int>> &empty) {
    if (line == 9) return true;
    int n = rests[line].size();
    vector<int> check(n, 0);
    auto ans = dfs(line, 0, n, rows, cols, grids, rests, empty, check);
    return ans;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rows(9, vector<int>(10, 0));
    vector<vector<int>> cols(9, vector<int>(10, 0));
    vector<vector<int>> grids(9, vector<int>(10, 0));
    vector<vector<int>> rests(9, vector<int>(0));
    vector<vector<int>> empty(9, vector<int>(0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                empty[i].push_back(j);
                continue;   
            }
            rows[i][board[i][j] - '0'] = 1;
            cols[j][board[i][j] - '0'] = 1;
            grids[(i / 3) * 3 + j / 3][board[i][j] - '0'] = 1;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (rows[i][j]) continue;
            rests[i].push_back(j);
        }
    }
    return is_valid_sudoku(0, rows, cols, grids, rests, empty);
}

int main() {
    return 0;
}
