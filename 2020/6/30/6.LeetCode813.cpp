/*************************************************************************
	> File Name: 6.LeetCode813.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月30日 星期二 15时57分24秒
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

double largestSumOfAverages(vector<int>& A, int K) {
    double dp[A.size() + 5][K + 5];
    int arr[A.size() + 5];
    memset(dp, 0, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < A.size(); i++) 
        arr[i + 1] = arr[i] + A[i];

    for (int i = 0; i < A.size(); i++) 
        dp[i][1] = (arr[A.size()] - arr[i]) * 1.0 / (A.size() - i);

    for (int l = 2; l <= K; l++) {
        double ans = 0.0;
        for (int i = A.size() - l; i >= 0; i--) {
            for (int j = i + 1; j <= A.size() - l + 1; j++) {
                ans = max(ans, dp[j][l - 1] + (arr[j + 1] - arr[i]) * 1.0 / (j - i + 1));
            }
            dp[i][l] = ans;
        }
    }
    return dp[0][K];
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
