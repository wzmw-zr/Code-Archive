/*************************************************************************
	> File Name: 2.LeetCode1198.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月26日 星期二 00时18分36秒
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

int smallestCommonElement(vector<vector<int>>& mat) {
    unordered_set<int> st;
    int n = mat.size(), m = mat[0].size(), ans = INT32_MAX;
    for (int i = 0; i < m; i++) st.insert(mat[0][i]);
    for (int i = 1; i < n && st.size(); i++) {
        unordered_set<int> temp;
        for (int j = 0; j < m; j++) {
            if (!st.count(mat[i][j])) continue;
            temp.insert(mat[i][j]);
        }
        st = temp;
    }
    if (!st.size()) return -1;
    for (int x : st) ans = min(ans, x);
    return ans;
}

int main() {
    return 0;
}
