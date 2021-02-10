/*************************************************************************
	> File Name: 2.LeetCode713.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月10日 星期三 09时15分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;
    int n = nums.size(), l = 0, r = 0, cnt = 0;
    long mul = 1;
    while (r < n) {
        mul *= nums[r];
        while (l <= r && mul >= k) mul /= nums[l++];
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}

int main() {
    return 0;
}
