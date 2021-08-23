/*************************************************************************
	> File Name: 1.LeetCode1646.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月23日 星期一 08时39分47秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getMaximumGenerated(int n) {
    if (n <= 1) return n;
    vector<int> nums(n + 1, 0);
    nums[0] = 0, nums[1] = 1;
    int ans = 1;
    for (int i = 0; i <= n; i++) {
        if (2 * i <= n) {
            nums[2 * i] = nums[i];
            ans = max(ans, nums[2 * i]);
        }
        if (2 * i + 1 <= n) {
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            ans = max(ans, nums[2 * i + 1]);
        }
    }
    return ans;
}

int main() {
    return 0;
}
