/*************************************************************************
	> File Name: 4.LeetCode5940.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月28日 星期日 10时40分44秒
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

int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 1;
    int mmax = INT32_MIN, mmin = INT32_MAX;
    for (int x : nums) mmax = max(x, mmax), mmin = min(x, mmin);
    int mmax_ind = 0, mmin_ind = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == mmax) mmax_ind = i;
        if (nums[i] == mmin) mmin_ind = i;
    }
    return min({max(mmax_ind + 1, mmin_ind + 1), max(n - mmax_ind, n - mmin_ind), mmax_ind + 1 + n - mmin_ind, mmin_ind + 1 + n - mmax_ind});
}

int main() {
    return 0;
}
