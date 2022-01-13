/*************************************************************************
	> File Name: 1.LeetCode747.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月13日 星期四 08时30分07秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int dominantIndex(vector<int>& nums) {
    int n = nums.size();
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (nums[ind] < nums[i]) ind = i;
    }
    for (int i = 0; i < n; i++) {
        if (ind == i) continue;
        if (nums[ind] >= 2 * nums[i]) continue;
        return -1;
    }
    return ind;
}

int main() {
    return 0;
}
