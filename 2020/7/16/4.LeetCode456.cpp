/*************************************************************************
	> File Name: 4.LeetCode456.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月16日 星期四 15时27分52秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int len = nums.size();
    if (len < 3) return false;
    vector<int> pre(len, 0);
    pre[0] = nums[0];
    for (int i = 1; i < len; i++) {
        pre[i] = min(nums[i], pre[i - 1]);
    }
    stack<int> st;
    for (int i = len - 1; i >= 0; i--) {
        if (nums[i] > pre[i]) {
            while (!st.empty() && pre[i] >= st.top()) st.pop();
            if (!st.empty() && st.top() < nums[i]) return true;
            st.push(nums[i]);
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (find132pattern(nums) ? "True" : "False") << endl;
    return 0;
}
