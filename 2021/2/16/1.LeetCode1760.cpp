/*************************************************************************
	> File Name: 1.LeetCode1760.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月16日 星期二 00时05分11秒
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

int get_cnt(vector<int> &nums, int mid) {
    int cnt = 0;
    for (int &x : nums) cnt += (x - 1) / mid;
    return cnt;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1, r = 1;
    for (int &x : nums) r = max(r, x);
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = get_cnt(nums, mid);
        if (cnt > maxOperations) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    return 0;
}
