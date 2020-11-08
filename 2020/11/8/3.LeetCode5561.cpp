/*************************************************************************
	> File Name: 3.LeetCode5561.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 10时32分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int getMaximumGenerated(int n) {
    vector<int> nums(n + 5, 0);
    nums[1] = 1;
    for (int i = 1; 2 * i <= n; i++) {
        if ((i * 2 >= 2) && (i * 2 <= n)) nums[2 * i] = nums[i];
        if (((i * 2 + 1) >= 2) && ((2 * i + 1) <= n)) nums[2 * i + 1] = nums[i] + nums[i + 1];
    }
    sort(nums.begin(), nums.end());
    return nums[nums.size() - 1];
}

int main() {
    int n;
    cin >> n;
    cout << getMaximumGenerated(n) << endl;
    return 0;
}
