/*************************************************************************
	> File Name: 2.LeetCode1826.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月11日 星期三 08时55分31秒
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

int maxSubArray(vector<int>& nums) {
    int preSum = nums[0], mmax = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if ((preSum + nums[i]) < nums[i]) preSum = nums[i];
        else preSum += nums[i];
        mmax = max(mmax, preSum);
    }
    return mmax;
}

int main() {
    return 0;
}
