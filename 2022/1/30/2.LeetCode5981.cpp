/*************************************************************************
	> File Name: 2.LeetCode5981.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月30日 星期日 10时37分54秒
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

vector<int> maxScoreIndices(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n + 1, 0);
    vector<int> right(n + 1, 0);
    for (int i = 0; i < n; i++) {
        left[i + 1] = left[i];
        if (nums[i] == 0) {
            left[i + 1]++;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        right[i] = right[i + 1];
        if (nums[i] == 1) {
            right[i]++;
        }
    }
    
    int mmax = INT32_MIN;
    for (int i = 0; i <= n; i++) {
        mmax = max(mmax, left[i] + right[i]);
    }
    
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
        if (mmax == left[i] + right[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    return 0;
}
