/*************************************************************************
	> File Name: 4.LeetCode33.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月27日 星期一 19时28分01秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int GetDivide(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    int len = r;
    int head = nums[0], tail = nums[r];
    if (head <= tail) return -1;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (nums[mid] > nums[len]) l = mid;
        else r = mid - 1;   
    }
    return l;
}

int B_S(vector<int> &nums, int l, int r, int target) {
    int mid = l;
    while (l < r) {
        mid = (l + r) >> 1;
        if (nums[mid] == target) return mid; 
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return nums[l] == target ? l : -1;
}

int search(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;
    int ind = GetDivide(nums);
    int res;
    if (ind == -1) res = B_S(nums, 0, nums.size() - 1, target);
    else {
        if (target >= nums[0]) res = B_S(nums, 0, ind, target);
        else res = B_S(nums, ind + 1, nums.size() - 1, target);
    }
    return res;
}

int main() {
    int n, m, tmp;
    cin >> n >> m;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << search(nums, m) << endl;
}
