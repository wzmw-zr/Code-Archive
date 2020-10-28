/*************************************************************************
	> File Name: 4.LeetCode1130.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月28日 星期三 19时36分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct Node {
    long mmax;
    long sum;

    Node() : mmax(0), sum(0) {}
    Node(long mmax) : mmax(mmax), sum(0) {}
    Node(long mmax, long sum) : mmax(mmax), sum(sum) {}
};

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    vector<vector<Node>> dp(n + 5, vector<Node>(n + 5));
    for (int i = 1; i <= n; i++) dp[i][i] = Node(arr[i - 1]);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            int flag = 0;
            cout << "l = " << j << ", r = " << j + i - 1 << endl;
            for (int k = j; k < j + i - 1; k++) {
                long left_max = dp[j][k].mmax;
                long right_max = dp[k + 1][j + i - 1].mmax;
                long left_sum = dp[j][k].sum;
                long right_sum = dp[k + 1][j + i - 1].sum;
                //cout << "[" << j << ", " << k << "]" << ", sum = " << left_sum << ", max = " << left_max << endl;
                //cout << "[" << k + 1 << ", " << j + i - 1 << "]" << ", sum = " << right_sum << ", max = " << right_max << endl;
                if (!flag) {
                    dp[j][j + i - 1].sum = left_sum + right_sum + left_max * right_max;
                    dp[j][j + i - 1].mmax = max(left_max, right_max);
                    flag = 1;
                } else {
                    if (dp[j][j + i - 1].sum > left_sum + right_sum + left_max * right_max) dp[j][j + i - 1].sum = left_sum + right_sum + left_max * right_max;
                }
                cout << dp[j][j + i - 1].sum << endl;
            }
            cout << endl;
        }
    }
    return dp[1][n].sum;
}

int main() {
    int n;
    vector<int> arr;
    while (cin >> n) arr.push_back(n);
    cout << mctFromLeafValues(arr) << endl;
    return 0;
}
