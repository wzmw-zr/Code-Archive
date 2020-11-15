/*************************************************************************
	> File Name: 1.LeetCode406.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月16日 星期一 00时11分10秒
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

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;
    map<int, vector<int>> mp;
    for (auto &x : people) {
        if (!mp.count(x[0])) mp[x[0]] = vector<int>(0);
        mp[x[0]].push_back(x[1]);
    }
    for (auto &x : mp) sort(x.second.begin(), x.second.end());
    unordered_map<int, int> done;
    while (mp.size()) {
        for (auto &x : mp) {
            int cnt = 0;
            for (auto &y : done) {
                if (y.first < x.first) continue;
                cnt += y.second;
            }
            if (x.second[0] <= cnt) {
                ans.push_back({x.first, x.second[0]});
                x.second.erase(x.second.begin());
                done[x.first]++;
                if (!x.second.size()) mp.erase(mp.find(x.first));
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> people;
    int x, y;
    while (cin >> x >> y) people.push_back({x, y});
    auto ans = reconstructQueue(people);
    for (auto &x : ans) cout << x[0] << " " << x[1] << endl;
    return 0;
}
