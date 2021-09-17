/*************************************************************************
	> File Name: 1.LeetCode36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月17日 星期五 13时58分32秒
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
void dfs(vector<int> &nums, int ind, int &n, vector<int> &check, vector<int> &path, vector<vector<int>> &ans) {
    if (ind == n) {
        ans.push_back(path);
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        path.push_back(nums[i]);
        dfs(nums, ind + 1, n, check, path, ans);
        path.pop_back();
        check[i] = 0;
    }
}

vector<vector<int>> generate_permutations(vector<int> &nums) {
    int n = nums.size();
    vector<int> check(n, 0);
    vector<vector<int>> ans;
    vector<int> path;
    dfs(nums, 0, n, check, path, ans);
    return ans;
}

bool is_valid(int ind, vector<int> &nums, vector<int> &pos, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (rows[ind][nums[i]] || cols[pos[i]][nums[i]] || grids[(ind / 3) * 3 + pos[i] / 3][nums[i]]) return false;
    }
    return true;
}

void mark(int ind, vector<int> &nums, vector<int> &pos, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        rows[ind][nums[i]] = 1;
        cols[pos[i]][nums[i]] = 1;
        grids[(ind / 3) * 3 + pos[i] / 3][nums[i]] = 1;
    }
}

void unmark(int ind, vector<int> &nums, vector<int> &pos, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        rows[ind][nums[i]] = 0;
        cols[pos[i]][nums[i]] = 0;
        grids[(ind / 3) * 3 + pos[i] / 3][nums[i]] = 0;
    }
}


bool is_valid_sudoku(int ind, vector<vector<int>> &rows, vector<vector<int>> &cols, vector<vector<int>> &grids, vector<vector<int>> &rests, vector<vector<int>> &empty) {
    if (ind == 9) return true;
    auto permutations = generate_permutations(rests[ind]);
    for (auto p : permutations) {
        if (!is_valid(ind, p, empty[ind], rows, cols, grids)) continue;
        mark(ind, p, empty[ind], rows, cols, grids);
        bool res = is_valid_sudoku(ind + 1, rows, cols, grids, rests, empty);
        unmark(ind, p, empty[ind], rows, cols, grids);
        if (res) return true;
    }
    return false;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rows(10, vector<int>(10, 0));
    vector<vector<int>> cols(10, vector<int>(10, 0));
    vector<vector<int>> grids(10, vector<int>(10, 0));
    vector<vector<int>> rests(10, vector<int>(0));
    vector<vector<int>> empty(10, vector<int>(0));

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

    #if 0
    for (int i = 0; i < 9; i++) {
        for (auto x : rests[i]) cout << x << " ";
        cout << endl;
    }
    #endif

    return is_valid_sudoku(0, rows, cols, grids, rests, empty);
}

int main() {
    return 0;
}
