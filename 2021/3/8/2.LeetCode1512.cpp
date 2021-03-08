/*************************************************************************
	> File Name: 2.LeetCode1512.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月08日 星期一 13时34分48秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int numIdenticalPairs(vector<int>& nums) {
    vector<int> cnt(101, 0);
    for (int &x : nums) cnt[x]++;
    int ans = 0;
    for (int &x : cnt) ans += x * (x - 1) / 2;
    return ans;
}


int main() {
    return 0;
}
