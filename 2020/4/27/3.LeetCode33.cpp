/*************************************************************************
	> File Name: 3.LeetCode33.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月27日 星期一 13时40分54秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int Divide(vector<int> &nums) {
    int l = -1, r = nums.size();
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (mid == -1) return -1;
        if (nums[mid] == nums[0]) {
            if (nums[0] > nums[1]) return 0;
            return -1;
        }
        if (nums[mid] > nums[0]) l = mid;
        else r = mid - 1;
    }
    return l;
}

int B_S(vector<int> &nums, int l, int r, int target) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return nums[l] == target ? l : -1;
}

int search(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1 && nums[0] != target) return -1; 
    if (nums.size() == 1 && nums[0] == target) return 0; 
    int divide = Divide(nums);
    return divide;
    int res = B_S(nums, 0, divide, target);
    if (res != -1) return res;
    res = B_S(nums, divide + 1, nums.size() - 1, target);
    return res;
}

int main() {    
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    cout << search(nums, m) << endl;
    return 0;
}
