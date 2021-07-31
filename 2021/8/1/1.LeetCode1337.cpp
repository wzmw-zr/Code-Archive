/*************************************************************************
	> File Name: 1.LeetCode1337.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月01日 星期日 00时02分46秒
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

using PII = pair<int, int>;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    vector<PII> rows;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int x : mat[i]) sum += x;
        rows.push_back(PII(sum, i));
    }
    sort(rows.begin(), rows.end());
    vector<int> ans;
    for (int i = 0; i < k; i++) ans.push_back(rows[i].second);
    return ans;
}

int main() {
    return 0;
}
