/*************************************************************************
	> File Name: 4.LeetCode6005.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月13日 星期日 10时33分06秒
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

int minimumOperations(vector<int>& nums) {
    if (nums.size() == 1) {
        return 0;
    }
    map<int, int> odd, even;
    for (int i = 0; i < nums.size(); i++) {
        if (i & 1) {
            odd[nums[i]]++;
        } else {
            even[nums[i]]++;
        }
    }

    map<int, vector<int>> mp1, mp2;
    for (auto &&[x, cnt] : odd) {
        if (!mp1.count(cnt)) {
            mp1[cnt] = vector<int>();
        }
        mp1[cnt].push_back(x);
    }
    for (auto &&[x, cnt] : even) {
        if (!mp2.count(cnt)) {
            mp2[cnt] = vector<int>();
        }
        mp2[cnt].push_back(x);
    }

    auto iter_1 = mp1.rbegin();
    auto iter_2 = mp2.rbegin();

    if (iter_1->second.size() >= 2 || iter_2->second.size() >= 2 || iter_1->second[0] != iter_2->second[0]) {
        return nums.size() - iter_1->first - iter_2->first;
    }

    auto next_iter_1 = next(iter_1);
    auto next_iter_2 = next(iter_2);

    int n = nums.size();

    if (next_iter_1 == mp1.rend() && next_iter_2 == mp2.rend()) {
        return min(iter_1->first, iter_2->first);
    }
    if (next_iter_1 == mp1.rend()) {
        return min(n - iter_1->first - next_iter_2->first, n - iter_2->first);
    }
    if (next_iter_2 == mp2.rend()) {
        return min(n - iter_1->first, n - iter_2->first - next_iter_1->first);
    }
    return min(n - iter_1->first - next_iter_2->first, n - iter_2->first - next_iter_1->first);
}

int main() {
    return 0;
}
