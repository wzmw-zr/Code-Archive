/*************************************************************************
	> File Name: 1.LeetCode611.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月04日 星期三 00时05分49秒
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

// Broute Method
bool check(int x, int y, int z) {
    if ((x + y) > z) return true;
    return false;
}

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (check(nums[i], nums[j], nums[k])) ans++;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
