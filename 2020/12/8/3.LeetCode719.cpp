/*************************************************************************
	> File Name: 3.LeetCode719.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月08日 星期二 18时32分43秒
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

int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    priority_queue<int> que;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (que.size() < k) que.push(nums[j] - nums[i]);
            else {
                int temp = nums[j] - nums[i];
                if (temp >= que.top()) continue;
                que.pop();
                que.push(temp);
            }
        }
    }
    int ans = que.top();
    return ans;
}

int main() {
    int k, n;
    cin >> k;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << smallestDistancePair(nums, k) << endl;
    return 0;
}
