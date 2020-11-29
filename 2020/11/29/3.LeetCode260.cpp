/*************************************************************************
	> File Name: 3.LeetCode260.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月29日 星期日 08时39分52秒
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

vector<int> singleNumber(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    for (auto &x : mp) {
        if (x.second == 1) ans.push_back(x.first);
    }
    return ans;
}

int main() {
    return 0;
}
