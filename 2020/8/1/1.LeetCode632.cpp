/*************************************************************************
	> File Name: 1.LeetCode632.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 07时50分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 200000
#define H_MAX_N 100000

void handle(vector<int> &nums) {
    if (nums.size() == 0) return ;
    int tmp = nums[0];
    for (auto iter = nums.begin() + 1; iter != nums.end(); ) {
        if (tmp == *iter) {
            nums.erase(iter);
            continue;
        }
        tmp = *iter;
        iter++;
    }
}

void countPre(int ind, vector<vector<int>> &nums, vector<vector<int>> &pre) {
    int len = nums[ind].size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = nums[ind][i]; j < nums[ind][i + 1]; j++)
            pre[ind][H_MAX_N + j + 1] = i + 1;
    }
    for (int i = H_MAX_N + nums[ind][len - 1]; i <= MAX_N; i++) 
        pre[ind][i + 1] = len;
}

vector<int> check(int left, int right, int len, vector<vector<int>> &pre) {
    int ans = 0;
    vector<int> ret(2, -1);
    for (int i = left; i + len - 1 <= right; i++) {
        int tmp_ans = 1;
        for (int j = 0; j < pre.size(); j++) {
            if (pre[j][i + len - 1] - pre[j][i] >= 1) continue;
            tmp_ans = 0;
        }
        if (!tmp_ans) continue;
        ans = 1;
        ret[0] = i, ret[1] = i + len - 1;
        break;
    }
    return ret;
}

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    int mmin = INT32_MAX, mmax = INT32_MIN;
    for (int i = 0; i < k; i++) {
        if (nums[i].size() > 0) {
            mmin = min(mmin, nums[i][0]);   
            mmax = max(mmax, nums[i][nums[i].size() - 1]);
        }
    }
    for (int i = 0; i < k; i++) handle(nums[i]);
    vector<vector<int>> pre(k + 5, vector<int>(MAX_N + 5, 0));
    for (int i = 0; i < k; i++) countPre(i, nums, pre);
    int left = 1, right = mmax - mmin + 1, ans = INT32_MAX;
    vector<int> ret;
    while (left < right) {
        int mid = (left + right) / 2;
        vector<int> res = check(mmin, mmax, mid, pre);
        if (res[0] = -1) break;
        ret = res;
    }
    return ret;
}

int main() {
    return 0;
}
