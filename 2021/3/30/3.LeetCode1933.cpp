/*************************************************************************
	> File Name: 3.LeetCode1933.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月30日 星期二 00时33分07秒
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

bool check_path(unordered_map<int, unordered_set<int>> &mp, int start, int end, int n) {
    vector<int> check(n, 0);
    check[start] = 1;
    queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int temp = que.front();
        if (temp == end) return true;
        que.pop();
        for (int x : mp[temp]) {
            if (check[x]) continue;
            check[x] = 1;
            que.push(x);
        }
    }
    return false;
}

bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    unordered_map<int, unordered_set<int>> mp;
    for (int i = 0; i < n; i++) mp[i] = unordered_set<int>(0);
    for (auto &&x : graph) {
        if (x[0] == x[1]) continue;
        mp[x[0]].insert(x[1]);   
    }
    if (check_path(mp, start, target, n)) return true;
    // if (check_path(mp, start, target, n) || check_path(mp, target, start, n)) return true;
    return false;
}

int main() {
    return 0;
}
