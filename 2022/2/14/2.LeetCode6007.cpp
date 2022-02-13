/*************************************************************************
	> File Name: 2.LeetCode6007.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月14日 星期一 01时37分16秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int maximumANDSum(vector<int>& nums, int numSlots) {
    int dp[1 << (2 * numSlots)];
    memset(dp, 0, sizeof(dp));
    int ans = INT32_MIN;
    for (int i = 0; i < (1 << (2 * numSlots)); i++) {
        int c = __builtin_popcount(i);
        if (c >= nums.size()) {
            continue;
        }
        for (int j = 0; j < 2 * numSlots; j++) {
            if ((i & (1 << j)) == 0) {
                int s = i | (1 << j);
                dp[s] = max(dp[s], dp[i] + ((j / 2 + 1) & nums[c]));
                ans = max(ans, dp[s]);
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
