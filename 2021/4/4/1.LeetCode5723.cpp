/*************************************************************************
	> File Name: 1.LeetCode5723.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月04日 星期日 10时34分01秒
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

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, unordered_set<int>> mp;
    for (auto &log : logs) {
        if (!mp.count(log[0])) mp[log[0]] = unordered_set<int>();
        mp[log[0]].insert(log[1]);
    }
    vector<int> ans(k, 0);
    for (auto &&[x, t]: mp) ans[(int) t.size() - 1]++;
    return ans;
}

int main() {
    return 0;
}
