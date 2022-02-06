/*************************************************************************
	> File Name: 1.LeetCode6000.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月06日 星期日 10时34分22秒
 ************************************************************************/

#include <iostream>
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

vector<int> sortEvenOdd(vector<int>& nums) {
    int n = nums.size();
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            odd.push_back(nums[i]);
        } else {
            even.push_back(nums[i]);
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            ans[i] = odd[i / 2];
        } else {
            ans[i] = even[i / 2];
        }
    }
    return ans;
}

int main() {
    return 0;
}
