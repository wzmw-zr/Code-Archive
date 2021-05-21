/*************************************************************************
	> File Name: 1.LeetCode810.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月22日 星期六 00时46分40秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool xorGame(vector<int> &nums) {
    if (!(nums.size() & 1)) return true;
    int t = 0;
    for (int x : nums) t ^= x;
    return t == 0;
}

int main() {
    return 0;
}
