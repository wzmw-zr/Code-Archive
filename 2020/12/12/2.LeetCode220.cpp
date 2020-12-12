/*************************************************************************
	> File Name: 2.LeetCode220.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月12日 星期六 08时38分41秒
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

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = 2; i + j - 1 < n && j - 1 <= k; j++) {
            if (abs(nums[i] - nums[i + j - 1]) <= t) return true;
        }
    }
    return false;
}

int main() {
    int k, t, n;
    vector<int> nums;
    cin >> k >> t;
    while (cin >> n) nums.push_back(n); 
    cout << (containsNearbyAlmostDuplicate(nums, k, t) ? "Yes" : "False") << endl;
    return 0;
}
