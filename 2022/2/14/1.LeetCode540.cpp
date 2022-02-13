/*************************************************************************
	> File Name: 1.LeetCode540.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月14日 星期一 00时03分36秒
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

int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == nums[mid + 1]) {
            if ((mid - l) & 1) {
                r = mid - 1;
            } else {
                l = mid + 2;
            }
        } else {
            if ((mid - l + 1) & 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    return nums[l];
}

int main() {
    return 0;
}
