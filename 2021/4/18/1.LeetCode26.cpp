/*************************************************************************
	> File Name: 1.LeetCode26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月18日 星期日 00时02分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int l = 0, r = 0, n = nums.size();
    int len = 0;
    while (r < n) {
        while (r < n && nums[r] == nums[l]) r++;
        nums[len] = nums[l];
        len++, l = r;
    }
    for (int i = n - 1; i > len - 1; i--) nums.pop_back();
    return len;
}

int main() {
    return 0;
}
