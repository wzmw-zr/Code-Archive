/*************************************************************************
	> File Name: 2.LeetCode5977.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月09日 星期日 10时41分01秒
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

int minSwaps(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) nums.push_back(nums[i]);
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += nums[i];
    int size = 0;
    int mmax = 0;
    int l = 0, r = 0;
    while (r < 2 * n) {
        size += nums[r];
        if (r - l + 1 == cnt + 1) {
            size -= nums[l];
            l++;
        }
        r++;
        mmax = max(mmax, size);
    }
    return cnt - mmax;
}

int main() {
    return 0;
}
