/*************************************************************************
	> File Name: 1.LeetCode1996.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月28日 星期五 09时11分19秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int find_last_lt(vector<int> &nums, int mmax) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] < mmax) l = mid;
        else r = mid - 1;
    }
    return l;
}

int numberOfWeakCharacters(vector<vector<int>>& properties) {
    // map with (attack, [defense_1, ..., defense_n])
    map<int, vector<int>> mp;
    for (auto &&p : properties) {
        if (!mp.count(p[0])) {
            mp[p[0]] = vector<int>();
        }
        mp[p[0]].push_back(p[1]);
    }
    for (auto &&[attack, defenses] : mp) {
        sort(defenses.begin(), defenses.end());
    }
    auto iter = mp.rbegin();
    auto end = mp.rend();
    int mmax = INT32_MIN;
    int cnt = 0;
    while (iter != end) {
        int last = find_last_lt(iter->second, mmax);
        if (iter->second[last] < mmax) cnt += last + 1;
        else cnt += last; // last index equal 0, and ge `param: mmax`.
        mmax = max(mmax, *iter->second.rbegin());
        iter++;
    }
    return cnt;
}

int main() {
    return 0;
}
