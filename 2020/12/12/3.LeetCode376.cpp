/*************************************************************************
	> File Name: 3.LeetCode376.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月12日 星期六 10时09分44秒
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

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return n;
    vector<int> up(n, 1), down(n, 1);
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) up[i] = max(up[i - 1], down[i - 1] + 1);
        else up[i] = up[i - 1];
        if (nums[i] < nums[i - 1]) down[i] = max(down[i - 1], up[i - 1] + 1);
        else down[i] = down[i - 1];
    }
    return max(up[n - 1], down[n - 1]);
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << wiggleMaxLength(nums) << endl;
    return 0;
}
