/*************************************************************************
	> File Name: 3.LeetCode2149.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月27日 星期四 08时51分57秒
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

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int pos_cnt = 0, neg_cnt = 0;
    for (int x : nums) {
        if (x > 0) {
            ans[pos_cnt * 2] = x;
            pos_cnt++;
        } else {
            ans[neg_cnt * 2 + 1] = x;
            neg_cnt++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
