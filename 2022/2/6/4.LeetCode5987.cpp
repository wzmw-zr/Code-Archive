/*************************************************************************
	> File Name: 4.LeetCode5987.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月06日 星期日 15时32分23秒
 ************************************************************************/

#include <iostream>
#include <string>
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

long long minimumDifference(vector<int>& nums) {
    int n = nums.size();
    vector<long long> first(n);
    vector<long long> second(n);
    priority_queue<int> left_queue;
    priority_queue<int, vector<int>, greater<int>> right_queue;
    long long left_sum = 0;
    long long right_sum = 0;
    for (int i = 0; i < n / 3; i++) {
        left_queue.push(nums[i]);
        left_sum += nums[i];
    }
    first[n / 3 - 1] = left_sum;
    for (int i = n / 3; i < 2 * n / 3; i++) {
        left_queue.push(nums[i]);
        int temp = left_queue.top();
        left_queue.pop();
        left_sum = left_sum - temp + nums[i];
        first[i] = left_sum;
    }

    for (int i = n - 1; i >= 2 * n / 3; i--) {
        right_queue.push(nums[i]);
        right_sum += nums[i];
    }
    second[2 * n / 3] = right_sum;
    for (int i = 2 * n / 3 - 1; i >= n / 3; i--) {
        right_queue.push(nums[i]);
        int temp = right_queue.top();
        right_queue.pop();
        right_sum = right_sum - temp + nums[i];
        second[i] = right_sum;
    }

    long long ans = INT64_MAX;
    for (int i = n / 3 - 1; i < 2 * n / 3; i++) {
        ans = min(ans, first[i] - second[i + 1]);
    }
    return ans;
}

int main() {
    return 0;
}
