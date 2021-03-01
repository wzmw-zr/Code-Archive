/*************************************************************************
	> File Name: 2.LeetCode268.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月01日 星期一 09时21分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 1; i <= n; i++) ans ^= i;
    for (int i = 0; i < n; i++) ans ^= nums[i];
    return ans;
}

int main() {
    return 0;
}
