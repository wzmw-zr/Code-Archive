/*************************************************************************
	> File Name: 3.LeetCode1086.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月10日 星期四 17时02分48秒
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

vector<vector<int>> highFive(vector<vector<int>>& items) {
    unordered_map<int, vector<int>> mp;
    for (auto &x: items) {
        if (!mp.count(x[0])) mp[x[0]] = vector<int>(0);
        mp[x[0]].push_back(x[1]);
    }
    vector<vector<int>> ans;
    for (auto &&[id, scores] : mp) {
        sort(scores.begin(), scores.end(), [](int a, int b) { return a > b; });   
        ans.push_back({id, (scores[0] + scores[1] + scores[2] + scores[3] + scores[4]) / 5});
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
