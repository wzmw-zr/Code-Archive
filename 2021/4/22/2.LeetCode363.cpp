/*************************************************************************
	> File Name: 2.LeetCode363.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月22日 星期四 00时56分18秒
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

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT32_MIN;
    for (int i = 0; i < m; i++) {
        vector<int> sum(n, 0);
        for (int j = i; j < m; j++) {
            set<int> st = {0};
            for (int k = 0; k < n; k++) {
                sum[k] += matrix[j][k];
            }
            int s = 0;
            for (auto x : sum) {
                s += x;
                auto iter = st.lower_bound(s - k);
                if (iter != st.end()) {
                    ans = max(ans, s - *iter);
                }
                st.insert(s);
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
