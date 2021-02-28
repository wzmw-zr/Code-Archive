/*************************************************************************
	> File Name: 2.LeetCode5689.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月28日 星期日 10时31分11秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int cnt = 0;
    if (ruleKey == "type") {
        for (auto &item : items) {
            if (item[0] == ruleValue) cnt++;
        }
    } else if (ruleKey == "color") {
        for (auto &item : items) {
            if (item[1] == ruleValue) cnt++;
        }
    } else {
        for (auto &item : items) {
            if (item[2] == ruleValue) cnt++;
        }
    }
    return cnt;
}

int main() {
    return 0;
}
