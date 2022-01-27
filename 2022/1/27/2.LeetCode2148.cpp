/*************************************************************************
	> File Name: 2.LeetCode2148.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月27日 星期四 08时39分03秒
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

int countElements(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mmin = nums[0], mmax = nums[nums.size() - 1];
    int ans = 0;
    for (int x : nums) {
        if (mmin < x && x < mmax) ans++;
    }
    return ans;
}

int main() {
    return 0;
}
