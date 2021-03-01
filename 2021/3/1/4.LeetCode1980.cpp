/*************************************************************************
	> File Name: 4.LeetCode1980.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月01日 星期一 09时37分23秒
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

vector<int> missingTwo(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> st;
    for (int &x : nums) st.insert(x);
    vector<int> ans;
    for (int i = 1; i <= n + 2; i++) {
        if (st.count(i)) continue;
        ans.push_back(i);
    }
    return ans;
}

int main() {
    return 0;
}
