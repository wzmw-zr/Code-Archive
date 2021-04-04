/*************************************************************************
	> File Name: 3.LeetCode5725.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月04日 星期日 11时25分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int countDifferentSubsequenceGCDs(vector<int>& nums) {
    unordered_set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (st.count(nums[i])) continue;
        unordered_set<int> temp;
        temp.insert(nums[i]);
        for (int x : st) temp.insert(gcd(x, nums[i]));
        for (int x : temp) st.insert(x);
    }
    return (int) st.size();
}

int main() {
    return 0;
}
