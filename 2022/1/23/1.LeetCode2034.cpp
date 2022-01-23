/*************************************************************************
	> File Name: 1.LeetCode2034.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月23日 星期日 11时50分54秒
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

class StockPrice {
public:
    map<int, int> mp_;
    multiset<int> st_;

    StockPrice() {}

    void update(int timestamp, int price) {
        if (mp_.count(timestamp)) {
            st_.erase(st_.find(mp_[timestamp]));
        }
        mp_[timestamp] = price;
        st_.insert(price);
    }

    int current() {
        return mp_.rbegin()->second;
    }

    int maximum() {
        return *st_.rbegin();
    }

    int minimum() {
        return *st_.begin();
    }
};

int main() {
    return 0;
}
