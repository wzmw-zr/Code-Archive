/*************************************************************************
	> File Name: 1.LeetCode645.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月04日 星期日 00时08分21秒
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

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<bool> check(n + 1, 0);
    vector<int> ans(2);
    for (auto x : nums) {
        if (check[x]) ans[0] = x;
        check[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        ans[1] = i;
        break;
    }
    return ans;
}

int main() {
    return 0;
}
