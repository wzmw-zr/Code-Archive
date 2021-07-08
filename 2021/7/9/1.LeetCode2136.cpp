/*************************************************************************
	> File Name: 1.LeetCode2136.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月09日 星期五 00时03分35秒
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

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int num : nums) mp[num]++;
    for (auto &&[num, cnt] : mp) {
        if (cnt * 2 > n) return num;
    }
    return -1;
}

int main() {
    return 0;
}
