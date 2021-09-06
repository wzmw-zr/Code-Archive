/*************************************************************************
	> File Name: 1.LeetCode704.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月06日 星期一 10时04分53秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return nums[l] == target ? l : -1;
}

int main() {
    return 0;
}
