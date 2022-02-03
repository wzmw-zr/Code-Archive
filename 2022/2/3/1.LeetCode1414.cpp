/*************************************************************************
	> File Name: 1.LeetCode1414.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月03日 星期四 09时08分11秒
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

int find_last_le(vector<int> &nums, int target) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= target) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int findMinFibonacciNumbers(int k) {
    vector<int> nums = {1, 1};
    while (*nums.rbegin() <= 1e9) {
        nums.push_back(*nums.rbegin() + *next(nums.rbegin()));
    }
    int ans = 0;
    while (k) {
        int ind = find_last_le(nums, k);
        k -= nums[ind];
        ans++;
    }
    return ans;
}

int main() {
    int k;
    cin >> k;
    cout << findMinFibonacciNumbers(k) << endl;
    return 0;
}
