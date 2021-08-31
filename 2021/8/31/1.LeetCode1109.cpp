/*************************************************************************
	> File Name: 1.LeetCode1109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月31日 星期二 13时57分56秒
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

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n + 5, 0);
    vector<int> ans;
    for (auto x : bookings) {
        diff[x[0]] += x[2];
        diff[x[1] + 1] -= x[2];
    }
    for (int i = 1; i <= n; i++) {
        ans.push_back(diff[i]);
        diff[i + 1] += diff[i];
    }
    return ans;
}

int main() {
    return 0;
}
