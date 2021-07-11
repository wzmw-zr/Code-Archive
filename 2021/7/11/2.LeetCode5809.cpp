/*************************************************************************
	> File Name: 2.LeetCode5809.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月11日 星期日 10时33分49秒
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

int countPalindromicSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> pre_sum;
    vector<int> pre(26, 0);
    for (int i = 0; i < n; i++) {
        pre[s[i] - 'a']++;
        pre_sum.push_back(pre);
    }
    vector<vector<int>> check(26, vector<int>(26, 0));
    for (int i = 1; i < n - 1; i++) {
        vector<int> temp(26);
        for (int j = 0; j < 26; j++) {
            temp[j] = pre[j] - pre_sum[i][j];
            if (temp[j] && pre_sum[i - 1][j]) check[s[i] - 'a'][j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) ans += check[i][j];
    }
    return ans;
}

int main() {
    return 0;
}
