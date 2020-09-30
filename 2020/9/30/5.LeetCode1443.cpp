/*************************************************************************
	> File Name: 5.LeetCode1443.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月30日 星期三 18时56分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int dfs(int ind, map<int, vector<int>> &mp, vector<bool> &hasApple) {
    if (mp.find(ind) == mp.end()) return hasApple[ind] ? 1 : 0;
    int ret = 0;
    for (auto &x : mp[ind]) {
        int temp = dfs(x, mp, hasApple);
        switch (temp) {
            case 0 : break;
            case 1 : ret += 2; break;
            default : ret += temp + 2;
        }
    }
    if (!ret) return hasApple[ind] ? 1 : 0;
    return ret;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    map<int, vector<int>> mp;
    for (auto &x : edges) {
        if (mp.find(x[0]) == mp.end()) mp[x[0]] = vector<int>(0, 0);
        mp[x[0]].push_back(x[1]);
    }
    return dfs(0, mp, hasApple);
}

int main() {
    return 0;
}
