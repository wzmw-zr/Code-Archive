/*************************************************************************
	> File Name: 1.LeetCode456.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月24日 星期三 00时11分32秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

# if 0
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] < nums[k] && nums[k] < nums[j]) return true;
            }
        }
    }
    return false;
}
#endif

typedef pair<int, int> PII;

bool find132pattern(vector<int>& nums) {
    set<PII> left, right;
    int n = nums.size();
    vector<int> left_min(n, -1), right_nearest_min(n, n);
    for (int i = 0; i < n; i++) {
        PII t(nums[i], i);
        left.insert(t);
        auto iter = left.find(t);
        if (iter == left.begin()) continue;
        left_min[i] = left.begin()->second;
    }
    for (int i = n - 1; i >= 0; i--) {
        PII t(nums[i], i);
        right.insert(t);
        auto iter = right.find(t);
        if (iter == right.begin()) continue;
        iter--;
        right_nearest_min[i] = iter->second;
    }
    for (int i = 0; i < n; i++) {
        if (left_min[i] == -1 || right_nearest_min[i] == n) continue;
        if (nums[left_min[i]] < nums[right_nearest_min[i]]) return true;
    }
    return false;
}


int main() {
    return 0;
}
