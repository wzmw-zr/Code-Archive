/*************************************************************************
	> File Name: 4.LeetCode677.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月21日 星期六 08时33分58秒
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
using namespace std;

class MapSum {
public:
    unordered_map<string, int> mp;

    MapSum() {}

    void insert(string key, int val) {
        mp[key] = val;
    }

    int sum(string prefix) {
        int ans = 0;
        for (auto &x : mp) {
            if (x.first.size() < prefix.size()) continue;
            if (prefix == x.first.substr(0, prefix.size())) ans += x.second;
        }
        return ans;
    }
};

int main() {
    return 0;
}
