/*************************************************************************
	> File Name: 3.LeetCode5777.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月06日 星期日 10时42分32秒
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

int reductionOperations(vector<int>& nums) {
    map<int, int> mp;
    for (int x : nums) mp[x]++;
    auto iter = prev(mp.end());
    int cnt = 0;
    int ans = 0;
    while (iter != mp.begin()) {
        cnt += iter->second;
        iter = prev(iter);
        ans += cnt;
    }
    return ans;
}

int main() {
    return 0;
}
