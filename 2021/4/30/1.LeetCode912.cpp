/*************************************************************************
	> File Name: 1.LeetCode912.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月30日 星期五 00时09分02秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int left, int right) {
    int ind = 0, mid = (left + right) / 2;
    int x = left, y = mid + 1;
    int len = right - left + 1;
    vector<int> temp(len);
    while ((x <= mid) || (y <= right)) {
        if (x <= mid && (y > right || nums[x] < nums[y])) temp[ind++] = nums[x++];
        else temp[ind++] = nums[y++];
    }
    for (int i = 0; i < len; i++) nums[left + i] = temp[i];
}

void merge_sort(vector<int> &nums, int left, int right) {
    if (left >= right) return ;
    int mid = (left + right) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, right);
}

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    merge_sort(nums, 0, n - 1);
    return nums;
}

int main() {
    int x;
    vector<int> nums;
    while (cin >> x) nums.push_back(x);
    auto ans = sortArray(nums);
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
