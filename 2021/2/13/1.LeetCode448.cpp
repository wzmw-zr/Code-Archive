/*************************************************************************
	> File Name: 1.LeetCode448.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月13日 星期六 00时01分24秒
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

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> cnt(n + 1, 0), ans;
    for (int &x : nums) cnt[x]++;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) continue;
        ans.push_back(i);
    }
    return ans;
}

int main() {
    return 0;
}
