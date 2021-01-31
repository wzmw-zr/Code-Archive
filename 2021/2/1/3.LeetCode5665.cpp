/*************************************************************************
	> File Name: 3.LeetCode5665.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月01日 星期一 01时36分02秒
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

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    int n = adjacentPairs.size() + 1;
    unordered_map<int, int> cnt;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> check;
    for (auto &x : adjacentPairs) {
        cnt[x[0]]++;
        cnt[x[1]]++;
        check[x[0]] = 0;
        check[x[1]] = 0;
        if (!adj.count(x[0])) adj[x[0]] = vector<int>(0);
        if (!adj.count(x[1])) adj[x[1]] = vector<int>(0);
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    int start;
    vector<int> ans;
    for (auto &&[x, y] : cnt) {
        if (y > 1) continue;
        start = x;
        break;
    }
    while (n) {
        check[start] = 1;
        ans.push_back(start);
        check[start] = 1;
        n--;
        for (int &x : adj[start]) {
            if (check[x]) continue;
            start = x;
            break;
        }
    }
    return ans;
}

int main() {
    return 0;
}
