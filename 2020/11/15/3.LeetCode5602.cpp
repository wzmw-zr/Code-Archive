/*************************************************************************
	> File Name: 3.LeetCode5602.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月15日 星期日 10时52分10秒
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

int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> pre, suf;
    pre[0] = 0, suf[0] = 0;
    vector<int> temp = nums;
    int ans = INT32_MAX;
    temp.insert(temp.begin(), 0);
    for (int i = 1; i <= nums.size(); i++) {
        temp[i] += temp[i - 1];
        pre[temp[i]] = i;
    }
    temp = nums;
    temp.insert(temp.end(), 0);
    for (int i = nums.size() - 1, j = 1; i >= 0; i--, j++) {
        temp[i] += temp[i + 1];
        suf[temp[i]] = j;
    }
    for (auto &y : pre) {
        if (suf.count(x - y.first)) ans = min(ans, y.second + suf[x - y.first]);
    }
    if (ans > nums.size()) return -1;
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    int x, n;
    vector<int> nums;
    cin >> x;
    while (cin >> n) nums.push_back(n);
    cout << minOperations(nums, x) << endl;
    return 0;
}

