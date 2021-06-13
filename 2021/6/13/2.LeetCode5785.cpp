/*************************************************************************
	> File Name: 2.LeetCode5785.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月13日 星期日 11时03分37秒
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

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    int n = triplets.size();
    vector<int> ans(3, 0);
    for (int i = 0; i < n; i++) {
        if ((triplets[i][0] <= target[0]) && (triplets[i][1] <= target[1]) && (triplets[i][2] <= target[2])) {
            ans[0] = max(ans[0], triplets[i][0]);
            ans[1] = max(ans[1], triplets[i][1]);
            ans[2] = max(ans[2], triplets[i][2]);
        }
    }
    return (ans[0] == target[0]) && (ans[1] == target[1]) && (ans[2] == target[2]);
}

int main() {
    return 0;
}
