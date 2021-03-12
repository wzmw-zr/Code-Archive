/*************************************************************************
	> File Name: 2.LeetCode1972.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月12日 星期五 14时43分58秒
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

vector<vector<int>> pairSums(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int &x : nums) mp[x]++;
    vector<vector<int>> ans;
    for (int &x : nums) {
        if (!mp[x]) continue;
        int y = target - x;
        if (y == x && mp[x] == 1)  continue;
        if (!mp.count(y) || !mp[y]) continue;
        ans.push_back(vector<int>({x, y}));
        mp[x]--;
        mp[y]--;
    }
    return ans;
}

int main() {
    return 0;
}
