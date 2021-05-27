/*************************************************************************
	> File Name: 2.LeetCode477.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月28日 星期五 00时16分41秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    vector<vector<int>> cnts(32, vector<int>(2, 0));
    for (int num : nums) {
        for (int i = 0; i < 32; i++) {
            int t = num & 1;
            ans += cnts[i][!t];
            cnts[i][t]++;
            num >>= 1;
        }
    }
    return ans;
}

int main() {
    return 0;
}
