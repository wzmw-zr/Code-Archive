/*************************************************************************
	> File Name: 2.LeetCode457.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月07日 星期六 08时53分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    auto next = [&](int i) {
        return (i + (nums[i] % n) + n) % n;
    };
    for (int i = 0; i < n; i++) {
        if (!nums[i]) continue;
        int slow = i, fast = next(i);
        while ((nums[i] * nums[slow] > 0) && (nums[i] * nums[fast] > 0)) {
            if (slow == fast) {
                if (slow != next(slow)) return true;
                else break;
            }
            slow = next(slow);
            fast = next(next(fast));
        }
        int ind = i;
        while (nums[ind] * nums[next(ind)] > 0) {
            int temp = ind;
            ind = next(ind);
            nums[temp] = 0;
        }
    }
    return false;
}

int main() {
    return 0;
}
