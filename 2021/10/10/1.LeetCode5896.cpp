/*************************************************************************
	> File Name: 1.LeetCode5896.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月10日 星期日 10时55分34秒
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

class StockPrice {
public:
    map<int, int> time_price;
    map<int, int> price_cnt;

    StockPrice() {}

    void update(int timestamp, int price) {
        if (time_price.count(timestamp)) {
            int t = time_price[timestamp];
            if (!(--price_cnt[t])) price_cnt.erase(price_cnt.find(t));
        }
        time_price[timestamp] = price;
        price_cnt[price]++;
    }

    int current() {
        return time_price.rbegin()->second;
    }

    int maximum() {
        return price_cnt.rbegin()->first;
    }

    int minimum() {
        return price_cnt.begin()->first;
    }
};

int main() {
    return 0;
}
