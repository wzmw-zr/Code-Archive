/*************************************************************************
	> File Name: 2.LeetCode210.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月10日 星期二 08时21分40秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, int> from;
    for (int i = 0; i < numCourses; i++) from[i] = 0;
    unordered_map<int, vector<int>> to;
    for (auto &x : prerequisites) {
        from[x[0]]++;
        if (!to.count(x[1])) to[x[1]] = vector<int>(0);
        to[x[1]].push_back(x[0]);
    }
    queue<int> que;
    for (auto &x : from) {
        if (x.second) continue;
        que.push(x.first);
    }
    vector<int> ans;
    while (!que.empty()) {
        int ind = que.front();
        que.pop();
        ans.push_back(ind);
        for (int x : to[ind]) {
            if (!(--from[x])) que.push(x);
        }
        to.erase(to.find(ind));
        numCourses--;
    }
    return numCourses ? vector<int>(0) : ans;
}

int main() {
    int numCourses, x, y;
    vector<vector<int>> prerequisites;
    cin >> numCourses;
    while (cin >> x >> y) prerequisites.push_back({x, y});
    auto ans = findOrder(numCourses, prerequisites);
    for (auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
