/*************************************************************************
	> File Name: 3.LeetCode1462.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月10日 星期二 09时01分28秒
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

vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    unordered_map<int, int> to;
    unordered_map<int, vector<int>> from, out;
    unordered_map<int, unordered_set<int>> after;
    for (int i = 0; i < n; i++) {
        to[i] = 0;
        after[i] = unordered_set<int>();
        from[i] = vector<int>(0);
        out[i] = vector<int>(0);
    }
    for (auto x : prerequisites) {
        to[x[0]]++;
        from[x[1]].push_back(x[0]);
        out[x[0]].push_back(x[1]);
    }
    queue<int> que;
    for (auto &x : to) {
        if (x.second) continue;
        que.push(x.first);
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop();
        for (int x : from[ind]) {
            if (!(--to[x])) que.push(x);
        }  
        from.erase(from.find(ind));
        after[ind].insert(ind);
        for (int x : out[ind]) {
            for (int y : after[x]) after[ind].insert(y);
        }
    }
    vector<bool> ans;
    for (auto &x : queries) {
        if (after[x[0]].find(x[1]) == after[x[0]].end()) ans.push_back(false);
        else ans.push_back(true);
    }
    return ans;
}

int main() {
    return 0;
}
