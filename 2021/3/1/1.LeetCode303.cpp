/*************************************************************************
	> File Name: 1.LeetCode303.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月01日 星期一 00时03分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class NumArray {
public:
    vector<int> pre_sum;
    NumArray(vector<int>& nums) : pre_sum(nums.size() + 1, 0){
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            pre_sum[i + 1] = pre_sum[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return pre_sum[j + 1] - pre_sum[i];
    }
};

int main() {
    return 0;
}
