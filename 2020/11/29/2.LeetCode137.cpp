/*************************************************************************
	> File Name: 2.LeetCode137.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月29日 星期日 08时37分15秒
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

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    for (auto &x : mp) {
        if (x.second == 1) return x.first;
    }
    return 0;
}

int main() {
    return 0;
}
