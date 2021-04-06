/*************************************************************************
	> File Name: 2.LeetCode1847.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月06日 星期二 22时19分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int binary_search(vector<int> &nums, int x) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

int purchasePlans(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    const long mod = 1e9 + 7;
    long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= target) break;
        int rest = target - nums[i];
        int ind = binary_search(nums, rest);
        if (ind == 0 && nums[ind] > rest) break;
        if (nums[i] <= rest) cnt += ind;
        else cnt += ind + 1;
    }
    cnt /= 2;
    cnt %= mod;
    return cnt;
}

int main() {
    return 0;
}
