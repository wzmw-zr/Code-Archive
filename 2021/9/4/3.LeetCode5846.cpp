/*************************************************************************
	> File Name: 3.LeetCode5846.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月04日 星期六 22时34分18秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findMiddleIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    vector<int> suf(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
    for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + nums[i];
    for (int i = 0; i < n; i++) {
        if (pre[i] == suf[i + 1]) return i;
    }
    return -1;
}

int main() {
    return 0;
}
