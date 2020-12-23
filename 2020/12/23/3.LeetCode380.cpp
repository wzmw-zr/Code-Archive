/*************************************************************************
	> File Name: 3.LeetCode380.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月23日 星期三 09时58分45秒
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

class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> nums;

    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        if (mp.count(val)) return false;
        mp[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) return false;
        int ind_1 = mp[val], ind_2 = nums.size() - 1;
        mp[nums[ind_2]] = ind_1;
        swap(nums[ind_1], nums[ind_2]);
        mp.erase(mp.find(val));
        nums.pop_back();
        return true;
    }

    int getRandom() {
        int ind = rand() % nums.size();
        return nums[ind];
    }
};

int main() {
    return 0;
}
