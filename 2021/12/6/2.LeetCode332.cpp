/*************************************************************************
	> File Name: 2.LeetCode332.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月06日 星期一 14时35分25秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;


void dfs(map<string, vector<string>> &mp, string place, vector<string> &ans) {
    while (mp[place].size()) {
        string next = *(mp[place].rbegin());
        mp[place].pop_back();
        dfs(mp, next, ans);
    }
    ans.push_back(place);
}


vector<string> findItinerary(vector<vector<string>>& tickets) {
    map<string, vector<string>> mp;
    unordered_map<string, int> in_degree;
    for (auto &&ticket : tickets) {
        if (!mp.count(ticket[0])) mp[ticket[0]] = vector<string>();
        mp[ticket[0]].push_back(ticket[1]);
        if (!mp.count(ticket[1])) mp[ticket[1]] = vector<string>();
        if (in_degree.count(ticket[0])) in_degree[ticket[0]] = 0;
        in_degree[ticket[1]]++;
    }
    for (auto &&[x, next] : mp) sort(next.begin(), next.end(), [](string &a, string &b) { return a > b; });
    vector<string> ans;
    dfs(mp, "JFK", ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
