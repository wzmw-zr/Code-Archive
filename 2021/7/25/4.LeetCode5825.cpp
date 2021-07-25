/*************************************************************************
	> File Name: 4.LeetCode5825.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月25日 星期日 10时54分41秒
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

void generate_permutations(int ind, int &m, unordered_set<int> &st, vector<int> &permutation, vector<vector<int>> &permutations) {
    if (ind == m) {
        permutations.push_back(permutation);
        return ;
    }
    auto t_st = st;
    for (int t_ind : t_st) {
        permutation[ind] = t_ind;
        st.erase(t_ind);
        generate_permutations(ind + 1, m, st, permutation, permutations);
        st.insert(t_ind);
    }
}

int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    int m = students.size(), n = students[0].size();
    vector<vector<int>> permutations;
    unordered_set<int> st;
    for (int i = 0; i < m; i++) st.insert(i);
    vector<int> permutation(m);
    generate_permutations(0, m, st, permutation, permutations);
    int ans = 0;
    for (auto p : permutations) {
        int t = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) t += students[i][j] == mentors[p[i]][j] ? 1 : 0;
        }
        ans = max(ans, t);
    }
    return ans;
}

int main() {
    return 0;
}
