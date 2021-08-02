/*************************************************************************
	> File Name: 1.LeetCode581.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月03日 星期二 00时09分33秒
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

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int left = -1, right = -1;
    for (int i = 0; i < n; i++) {
        if (temp[i] == nums[i]) continue;
        left = i;
        break;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (temp[i] == nums[i]) continue;
        right = i;
        break;
    }
    return left == -1 ? 0 : right - left + 1;
}

int main() {
    return 0;
}
