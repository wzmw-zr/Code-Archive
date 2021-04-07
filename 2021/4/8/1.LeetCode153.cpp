/*************************************************************************
	> File Name: 1.LeetCode153.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月08日 星期四 00时03分34秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] > nums[0]) l = mid;
        else r = mid - 1;
    }
    int min_ind = (l + 1) % n;
    return nums[min_ind];
}

int main() {
    return 0;
}
