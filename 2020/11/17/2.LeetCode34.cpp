/*************************************************************************
	> File Name: 2.LeetCode34.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月17日 星期二 00时15分31秒
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

int b_s_f(vector<int> &nums, int left, int right, int target) {
    if (right == -1) return -1;
    while (left != right) {
        int mid = (left + right) >> 1;
        if (nums[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return nums[left] == target ? left : -1;
}

int b_s_l(vector<int> &nums, int left, int right, int target) {
    if (right == -1) return -1;
    while (left != right) {
        int mid = (left + right + 1) >> 1;
        if (nums[mid] <= target) left = mid;
        else right = mid - 1;
    }
    return nums[left] == target ? left : -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.push_back(b_s_f(nums, 0, nums.size() - 1, target));
    ans.push_back(b_s_l(nums, 0, nums.size() - 1, target));
    return ans;
}

int main() {
    int target, x;
    vector<int> nums;
    cin >> target;
    while (cin >> x) nums.push_back(x);
    auto ans = searchRange(nums, target);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
