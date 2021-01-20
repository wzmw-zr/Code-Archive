/*************************************************************************
	> File Name: 4.LeetCode1109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月20日 星期三 21时44分05秒
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

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> dis(n + 2, 0);
    vector<int> ans(n);
    for (auto &x : bookings) {
        dis[x[0]] += x[2];
        dis[x[1] + 1] -= x[2];
    }
    for (int i = 1; i <= n; i++) {
        ans[i - 1] = dis[i];
        dis[i + 1] += dis[i];
    }
    return ans;
}

int main() {
    return 0;
}
