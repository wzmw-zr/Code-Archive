/*************************************************************************
	> File Name: 1.LeetCode2027.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月16日 星期五 00时04分09秒
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

int find_left(vector<int> &nums, int target) {
    int l = 0, r = (int) nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_right(vector<int> &nums, int target) {
    int l = 0, r = (int) nums.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0] == target ? 1 : 0;
    if (nums[0] > target || *nums.rbegin() < target) return 0;
    int ind_1 = find_left(nums, target);
    int ind_2 = find_right(nums, target);
    return ind_2 - ind_1 + 1;
}

int main() {
    return 0;
}
