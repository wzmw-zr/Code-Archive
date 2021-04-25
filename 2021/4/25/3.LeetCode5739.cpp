/*************************************************************************
	> File Name: 3.LeetCode5739.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月25日 星期日 10时41分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// WA
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); 
    int n = nums.size();
    int ans = 1;
    int l = 0, r = 0;
    long dis = 0;
    while (r < n) {
        if (l == r) {
            r++;
            continue;
        }
        long off = (nums[r] - nums[r - 1]) * (r - l);
        dis += off;
        while (dis > k) {
            dis -= (nums[r] - nums[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main() {
    return 0;
}
