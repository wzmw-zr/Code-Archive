/*************************************************************************
	> File Name: 1.LeetCode35.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月17日 星期五 00时49分31秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) return i;
    }
    return nums.size();
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << searchInsert(nums, target) << endl;
    return 0;
}
