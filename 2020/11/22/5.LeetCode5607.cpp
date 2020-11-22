/*************************************************************************
	> File Name: 5.LeetCode5607.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月22日 星期日 10时50分21秒
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

typedef pair<int, int> PII;
int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int ans = 0;
    vector<PII> pre(n + 1, PII(0, 0)), suf(n + 1, PII(0, 0));
    for (int x : nums) sum += x;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            pre[i + 1].first = pre[i].first;
            pre[i + 1].second = pre[i].second + nums[i];
        } else {
            pre[i + 1].first = pre[i].first + nums[i];
            pre[i + 1].second = pre[i].second;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i & 1) {
            suf[i].first = suf[i + 1].first;
            suf[i].second = suf[i + 1].second + nums[i];
        } else {
            suf[i].first = suf[i + 1].first + nums[i];
            suf[i].second = suf[i + 1].second;
        }
    }
    for (int i = 0; i < n; i++) {
        int temp_sum = sum - nums[i];
        if (i & 1) {
            int temp = pre[i + 1].second - nums[i] + suf[i].first;
            if (temp * 2 == temp_sum) ans++;
        } else {
            int temp = pre[i + 1].first - nums[i] + suf[i].second;
            if (temp * 2 == temp_sum) ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << waysToMakeFair(nums) << endl;
    return 0;
}
