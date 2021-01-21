/*************************************************************************
	> File Name: 1.LeetCode989.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月22日 星期五 00时01分15秒
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

vector<int> add(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < m; i++) ans[i] += A[i] + B[i];
    for (int i = m; i < n; i++) ans[i] += A[i];
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] < 10) continue;
        if (i + 1 == ans.size()) ans.push_back(0);
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    return ans;
}

vector<int> addToArrayForm(vector<int>& A, int K) {
    reverse(A.begin(), A.end());
    vector<int> B;
    do {
        B.push_back(K % 10);
        K /= 10;
    } while (K);
    vector<int> ans;
    if (A.size() >= B.size()) ans = add(A, B);
    else ans = add(B, A);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
