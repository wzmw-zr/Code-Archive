/*************************************************************************
	> File Name: 1.LeetCode446.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月11日 星期三 00时06分40秒
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

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    vector<long> temp;
    for (int x : nums) temp.push_back(x);
    vector<unordered_map<long, int>> dp(n);
    vector<unordered_map<long, int>> part(n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long step = temp[i] - temp[j];
            part[i][step]++;
            if (dp[j].count(step)) {
                dp[i][step] += dp[j][step];   
                ans += dp[j][step];
            }
            if (part[j].count(step)) {
                dp[i][step] += part[j][step];
                ans += part[j][step];
            }
        }
    }
    return ans;
}

int main() {
    // int n;
    vector<int> nums(100, 0);
    // while (cin >> n) nums.push_back(n);
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}
