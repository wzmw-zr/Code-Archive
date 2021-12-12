/*************************************************************************
	> File Name: 2.LeetCode5953.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月12日 星期日 21时45分56秒
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

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    int mmax[n + 1][n + 1], mmin[n + 1][n + 1];
    memset(mmax, 0, sizeof(mmax));
    memset(mmin, 0, sizeof(mmin));
    for (int i = 0; i < n; i++) mmax[i][0] = nums[i], mmin[i][0] = nums[i];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            mmax[j][i] = max(mmax[j - 1][i - 1], nums[j]);
            mmin[j][i] = min(mmin[j - 1][i - 1], nums[j]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) ans += mmax[i][j] - mmin[i][j];
    }
    return ans;
}

int main() {
    return 0;
}
