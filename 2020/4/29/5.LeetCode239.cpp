/*************************************************************************
	> File Name: 5.LeetCode239.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 17时32分49秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ret;
    deque<int> dq;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i - dq.front() == k) dq.pop_front();
        if (i >= k - 1) ret.push_back(nums[dq.front()]);
    }
    return ret;
}

int main() {
    int n, m, k;
    vector<int> nums, res;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m;
        nums.push_back(m);
    }
    res = maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}
