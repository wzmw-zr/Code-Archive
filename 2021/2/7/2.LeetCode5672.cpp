/*************************************************************************
	> File Name: 2.LeetCode5672.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月07日 星期日 10时35分14秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool check(vector<int>& nums) {
    int cnt = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) cnt++;
    }
    if (cnt >= 2) return false;
    if (cnt == 0) return true;
    return nums[n - 1] <= nums[0];
}

int main() {
    return 0;
}
