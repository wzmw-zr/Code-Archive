/*************************************************************************
	> File Name: 1.LeetCode477.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月28日 星期五 00时02分20秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += __builtin_popcount(nums[i] ^ nums[j]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums;
    for (int i = 0; i <= 10000; i++) nums.push_back(i);
    cout << totalHammingDistance(nums) << endl;
    return 0;
}
