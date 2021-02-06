/*************************************************************************
	> File Name: 1.LeetCode665.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月07日 星期日 00时01分05秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int cnt = 0, n = nums.size();
    vector<int> temp = nums;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] <= nums[i + 1]) continue;
        nums[i + 1] = nums[i];
        cnt++;
    }
    if (cnt <= 1) return true;
    cnt = 0;
    for (int i = n - 1; i > 0; i--) {
        if (temp[i] >= temp[i - 1]) continue;
        temp[i - 1] = temp[i];
        cnt++;
    }
    if (cnt <= 1) return true;
    return false;
}

int main() {
    return 0;
}
