/*************************************************************************
	> File Name: 2.LeetCode1838.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月14日 星期五 00时36分05秒
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

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = 0;
    long dis = 0;
    int ans = 0;
    while (r < n) {
        while ((r + 1 < n) && nums[r] == nums[r + 1]) r++;
        ans = max(ans, r - l + 1);
        r++;
        if (r < n) {
            dis += (long) (r - l) * (long) (nums[r] - nums[r - 1]);
            while (dis > k) dis -= nums[r] - nums[l++];
        }
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    return 0;
}
