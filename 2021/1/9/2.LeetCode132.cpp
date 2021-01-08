/*************************************************************************
	> File Name: 2.LeetCode132.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月09日 星期六 00时53分42秒
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

int maxProfit(vector<int>& prices) {
    int buy_1 = prices[0] * -1;
    int sell_1 = 0;
    int buy_2 = prices[0] * -1;
    int sell_2 = 0;
    for (int i = 1; i < prices.size(); i++) {
        buy_1 = max(buy_1, prices[i] * -1);
        sell_1 = max(sell_1, buy_1 + prices[i]);
        buy_2 = max(buy_2, sell_1 - prices[i]);
        sell_2 = max(sell_2, buy_2 + prices[i]);
    }
    return sell_2;
}

int main() {
    return 0;
}
