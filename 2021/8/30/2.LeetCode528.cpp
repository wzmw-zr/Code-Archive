/*************************************************************************
	> File Name: 2.LeetCode528.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月30日 星期一 08时59分50秒
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
#include <ctime>
using namespace std;

class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& w) : nums((int) w.size() + 1, 0) {
        srand(time(0));
        int n = w.size();
        for (int i = 0; i < n; i++) nums[i + 1] = nums[i] + w[i];
    }

    int pickIndex() {
        int num = (rand() % (*nums.rbegin())) + 1;
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < num) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};


int main() {
    return 0;
}
