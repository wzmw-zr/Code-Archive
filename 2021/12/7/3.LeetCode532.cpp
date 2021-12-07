/*************************************************************************
	> File Name: 3.LeetCode532.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月07日 星期二 10时08分28秒
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

using PII = pair<int, int>;

int findPairs(vector<int>& nums, int k) {
    unordered_set<int> st;
    set<PII> p_st;
    for (int x : nums) {
        if (st.count(x - k) && !p_st.count(PII(x - k, x)) && !p_st.count(PII(x, x - k))) p_st.insert(PII(x - k, x)); 
        if (st.count(x + k) && !p_st.count(PII(x + k, x)) && !p_st.count(PII(x, x + k))) p_st.insert(PII(x + k, x));
        st.insert(x);
    }
    return p_st.size();
}

int main() {
    return 0;
}
