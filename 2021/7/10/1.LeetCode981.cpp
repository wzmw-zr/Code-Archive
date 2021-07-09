/*************************************************************************
	> File Name: 1.LeetCode981.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月10日 星期六 00时03分40秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> table;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (!table.count(key)) table[key] = map<int, string>();
        table[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (!table.count(key)) return "";
        string ans = "";
        for (auto iter = table[key].rbegin(); iter != table[key].rend(); iter++) {
            if (iter->first > timestamp) continue;
            ans = iter->second;
            break;
        }
        return ans;
    }
};

int main() {
    return 0;
}
