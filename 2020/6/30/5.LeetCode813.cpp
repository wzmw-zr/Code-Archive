/*************************************************************************
	> File Name: 5.LeetCode813.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月30日 星期二 15时18分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

double dfs(int ind, vector<int> &A, int K) {
    if (ind + K > A.size()) return 0.0;
    if (K == 1) {
        return (A[A.size() - 1] - A[ind]) * 1.0 / ((A.size() - ind) * 1.0);
    }
    double ret = 0.0, avg = 0.0;
    for (int i = 1; i <= A.size() - ind; i++) {
        int tmp = dfs(ind + i, A, K - 1);
        cout << tmp << endl;
        if (tmp > ret) {
            ret = tmp;
            avg = (A[ind + i - 1] - A[ind - 1]) * 1.0 / (i * 1.0);
        }
    }
    return ret + avg;
}

double largestSumOfAverages(vector<int>& A, int K) {
    vector<int> val(A.size() + 1, 0);
    for (int i = 1; i <= A.size(); i++) val[i] = val[i - 1] + A[i - 1];
    #if 0
    for (int i = 0; i < A.size(); i++) cout << A[i] << " ";
    cout << endl;
    #endif
    return dfs(1, val, K);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << largestSumOfAverages(A, k) << endl;
    return 0;
}
