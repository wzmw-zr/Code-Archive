/*************************************************************************
	> File Name: 2.LeetCode377.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月24日 星期六 00时23分42秒
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

unordered_map<int, int> mp;

int combinationSum4(vector<int>& nums, int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (mp.count(target)) return mp[target];
    int ans = 0;
    for (int x : nums) ans += combinationSum4(nums, target - x);
    mp[target] = ans;
    return ans;
}

int main() {
    int target, num;
    vector<int> nums;
    cin >> target;
    while (cin >> num) nums.push_back(num);
    cout << combinationSum4(nums, target) << endl;
    return 0;
}
