/*************************************************************************
	> File Name: 4.LeetCode5710.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月21日 星期日 10时37分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    map<int, long> buy, sell;
    for (auto &x : orders) {
        if (x[2] == 0) {
            buy[x[0]] += x[1];
            while (sell.size() > 0 && sell.begin()->first <= x[0]) {
                if (sell.begin()->second == buy[x[0]]) {
                    sell.erase(sell.begin());
                    buy.erase(buy.find(x[0]));
                    break;
                } else if (sell.begin()->second > buy[x[0]]) {
                    sell.begin()->second -= x[1];
                    buy.erase(buy.find(x[0]));
                    break;
                } else {
                    buy[x[0]] -= sell.begin()->second;
                    sell.erase(sell.begin());
                }
            } 
        } else {
            sell[x[0]] += x[1];
            while (buy.size() > 0 && buy.rbegin()->first >= x[0]) {
                if (buy.rbegin()->second == sell[x[0]]) {
                    buy.erase(buy.rbegin()->first);
                    sell.erase(sell.find(x[0]));
                    break;
                } else if (buy.rbegin()->second > sell[x[0]]) {
                    buy.rbegin()->second -= x[1];
                    sell.erase(sell.find(x[0]));
                    break;
                } else {
                    sell[x[0]] -= buy.rbegin()->second;
                    buy.erase(buy.rbegin()->first);
                }
            } 
        }
    }
    long ans = 0;
    int mod = 1e7 + 9;
    for (auto &&[price, cnt] : buy) ans = (ans + cnt) % mod;
    for (auto &&[price, cnt] : sell) ans = (ans + cnt) % mod;
    return ans;
}

int main() {
    return 0;
}
