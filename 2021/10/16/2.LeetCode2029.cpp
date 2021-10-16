/*************************************************************************
	> File Name: 2.LeetCode2029.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月16日 星期六 18时15分07秒
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

bool stoneGameIX(vector<int>& stones) {
    vector<int> nums(3, 0);
    for (int x : stones) nums[x % 3]++;
    if (nums[1] == 0 && nums[2] == 0) return false;
    if (nums[1] == 0 || nums[2] == 0) {
        int t = nums[1] ? nums[1] : nums[2];
        if (t <= 2) return false;
        return (nums[0] & 1) ? true : false;
    }
    int x = abs(nums[1] - nums[2]);
    if (x == 0) return (nums[0] & 1) ? false : true;
    if (nums[1] == 1 || nums[2] == 1) {
        if (x <= 2) return (nums[0] & 1) ? false : true;
        return true;
    }
    if (!(nums[0] & 1)) return true;
    if ((x <= 2) && (nums[0] & 1)) return false;
    return true;
}

int main() {
    vector<int> stones;
    int n;
    while (cin >> n) stones.push_back(n);
    cout << (stoneGameIX(stones) ? "True" : "False") << endl;
    return 0;
}
