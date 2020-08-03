/*************************************************************************
	> File Name: 1.LeetCode207.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月04日 星期二 00时15分51秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> in_degree(numCourses, 0);
    vector<vector<int>> edge(numCourses, vector<int>(0, 0));
    queue<int> que;
    for (auto &x : prerequisites) {
        edge[x[0]].push_back(x[1]);
        in_degree[x[1]]++;
    }
    int cnt = 0;
    for (int i = 0; i < numCourses; i++) {
        if (in_degree[i] == 0) que.push(i);
        else cnt++;
    }
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i = 0; i < edge[node].size(); i++) {
            if (--in_degree[edge[node][i]]) continue;
            que.push(edge[node][i]);
            cnt--;
        }
    }
    return cnt == 0;
}

int main() {
    return 0;
}
