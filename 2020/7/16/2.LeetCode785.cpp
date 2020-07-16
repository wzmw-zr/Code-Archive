/*************************************************************************
	> File Name: 2.LeetCode785.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月16日 星期四 08时16分28秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

#define NO_COLOR -1
#define WHITE 0
#define BLACK 1

bool isBipartite(vector<vector<int>> &graph) {
    vector<int> color(graph.size(), -1);
    queue<int> node;
    node.push(0);
    while (!node.empty()) {
        int tmp = node.front();
        node.pop();
        if (color[tmp] == NO_COLOR) color[tmp] = WHITE;
        for (int i = 0; i < graph[tmp].size(); i++) {
            if (color[graph[tmp][i]] == NO_COLOR) color[graph[tmp][i]] = !color[tmp];
            else if (color[graph[tmp][i]] == color[tmp]) return false;
            else continue;
            node.push(graph[tmp][i]);
        }
    }
    return true;
}

int main() {
    return 0;
}
