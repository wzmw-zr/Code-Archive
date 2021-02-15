/*************************************************************************
	> File Name: 5.LeetCode1760.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月15日 星期一 23时47分28秒
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

// TLE

int check(vector<int> &nums, int mid) {
    priority_queue<int> que;
    for (int &x : nums) que.push(x);
    int cnt = 0;
    while (!que.empty() && que.top() > mid) {
        que.push(mid);
        que.push(que.top() - mid);
        que.pop();
        cnt++;
    }
    return cnt;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1, r = 1;
    for (int &x : nums) r = max(r, x);
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = check(nums, mid);
        if (cnt > maxOperations) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    return 0;
}
