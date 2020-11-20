/*************************************************************************
	> File Name: 2.LeetCode229.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月21日 星期六 00时15分39秒
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

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    for (auto &x : mp) {
        if (x.second > (n / 3)) ans.push_back(x.first);
    }
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    auto ans = majorityElement(nums);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
