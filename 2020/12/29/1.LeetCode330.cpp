/*************************************************************************
	> File Name: 1.LeetCode330.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月29日 星期二 00时25分53秒
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

int minPatches(vector<int>& nums, int n) {
    long x = 1;
    int ans = 0; 
    for (int i = 0; i < nums.size(); ) {
        if (nums[i] <= x) x += nums[i++];
        else x *= 2, ans++;
    }
    while (x <= n) x *= 2, ans++;
    return ans;
}

int main() {
    return 0;
}
