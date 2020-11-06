/*************************************************************************
	> File Name: 1.LeetCode327.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月07日 星期六 00时04分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size(), cnt = 0;
    nums.insert(nums.begin(), 0);
    for (int i = 1; i <= n; i++) nums[i] += nums[i - 1];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int temp = nums[j] - nums[i - 1];
            if (temp >= lower && temp <= upper) cnt++;
        }
    }
    return cnt;
}

int main() {
    return 0;
}
