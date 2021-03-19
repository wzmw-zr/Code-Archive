/*************************************************************************
	> File Name: 3.LeetCode398.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月19日 星期五 19时13分49秒
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
#include<ctime>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int>& nums) {
        srand(time(0));
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!mp.count(nums[i])) mp[nums[i]] = vector<int>(0);
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int n = mp[target].size();
        int ind = rand() % n;
        return mp[target][ind];
    }
};

int main() {
    return 0;
}
