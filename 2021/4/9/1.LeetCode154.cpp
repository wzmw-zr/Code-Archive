/*************************************************************************
	> File Name: 1.LeetCode154.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月09日 星期五 00时20分06秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[r]) l = mid + 1;
        else if (nums[mid] < nums[r]) r = mid;
        else r--;
    }
    return nums[r];
}

int main() {
    return 0;
}
