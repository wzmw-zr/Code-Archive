/*************************************************************************
	> File Name: 1.LeetCode523.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月01日 星期五 10时41分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k) {
    if (nums.size() <= 1) return false;
    for (int i = 1; i < nums.size(); i++) nums[i] += nums[i - 1];
    for (int len = 2; len <= nums.size(); len++) {
        for (int i = 0; i <= nums.size() - len; i++) {
            if ((!k && nums[i + len - 1] - nums[i] == 0) || (nums[i + len - 1] - nums[i]) % k == 0) return true;
        }
    }
    return false;
}

int main() {
    int n, k, t;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    cout << (checkSubarraySum(nums, k) ? "True" : "False") << endl;
    return 0;
}
