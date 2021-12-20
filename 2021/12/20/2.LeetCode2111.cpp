/*************************************************************************
	> File Name: 2.LeetCode2111.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月20日 星期一 11时11分17秒
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

int find_first_greater(vector<int> &arr, int num, int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] > num) r = mid;
        else l = mid + 1;
    }
    return l;
}

int Increasing(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n + 1);
    dp[1] = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= dp[len]) {
            len++;
            dp[len] = arr[i];
        } else {
            int ind = find_first_greater(dp, arr[i], 1, len);
            dp[ind] = arr[i];
        }
    }
    return n - len;
}

int kIncreasing(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> arrs(k, vector<int>());
    for (int i = 0; i < n; i++) arrs[i % k].push_back(arr[i]);
    int ans = 0;
    for (int i = 0; i < k; i++) ans += Increasing(arrs[i]);
    return ans;
}

int main() {
    return 0;
}
