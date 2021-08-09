/*************************************************************************
	> File Name: 1.LeetCode413.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月10日 星期二 00时03分05秒
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
    if (nums.size() < 3) return 0;
    int l = 0, r = 1, n = nums.size(), dis = nums[1] - nums[0];
    int ans = 0;
    while ((l < n) && (r < n)) {
        dis = nums[r] - nums[l];
        while ((r < n) && ((nums[r] - nums[r - 1] == dis))) r++;
        int cnt = r - l;
        if (cnt >= 3) ans += (cnt - 1) * (cnt - 2) / 2;
        l = r - 1;
    }
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}
