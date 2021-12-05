/*************************************************************************
	> File Name: 2.LeetCode5942.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 10时31分27秒
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

void dfs(set<int> &st, vector<int> &cnts, int val, int step) {
    if (step == 3) {
        if (val & 1) return ;
        if (val >= 100) st.insert(val);
        return ;
    }
    for (int i = 0; i < 10; i++) {
        if (!cnts[i]) continue;
        cnts[i]--;
        dfs(st, cnts, val * 10 + i, step + 1);
        cnts[i]++;
    }
}

vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> cnts(10, 0);
    for (int x : digits) cnts[x]++;
    set<int> st;
    dfs(st, cnts, 0, 0);
    vector<int> ans(st.begin(), st.end());
    return ans;
}

int main() {
    return 0;
}
