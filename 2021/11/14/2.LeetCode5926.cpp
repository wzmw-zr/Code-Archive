/*************************************************************************
	> File Name: 2.LeetCode5926.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月14日 星期日 10时31分18秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

using PII = pair<int, int>;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int wzmw_zr_q1 = 0;
    int n = tickets.size();
    vector<int> ans(n);
    queue<PII> que;
    int t = 0;
    for (int i = 0; i < n; i++) que.push(PII(i, tickets[i]));
    while (!que.empty()) {
        auto temp = que.front();
        que.pop();
        t++;
        if (!(--temp.second)) ans[temp.first] = t;
        else que.push(temp);
    }
    return ans[k];
}

int main() {
    return 0;
}
