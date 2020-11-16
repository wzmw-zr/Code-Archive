/*************************************************************************
	> File Name: 2.LeetCode406.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月16日 星期一 07时56分38秒
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

struct BIT {
    int len;
    vector<int> num;

    BIT() = default;
    BIT(int n) : len(n), num(n + 1, 0) {}

    int lowbit(int x) { return x & -x; }

    void update(int ind, int val) {
        while (ind <= len) {
            num[ind] += val;
            ind += lowbit(ind);
        }
    }

    int query(int ind) {
        int ans = 0;
        while (ind) {
            ans += num[ind];
            ind -= lowbit(ind);
        }
        return ans;
    }
};

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;
    map<int, vector<int>> height;
    for (auto &x : people) {
        if (!height.count(x[0])) height[x[0]] = vector<int>(0);
        height[x[0]].push_back(x[1]);
    }
    for (auto &x : height) sort(x.second.begin(), x.second.end());
    unordered_map<int, int> mp;
    int ind = 0;
    for (auto &x : height) mp[x.first] = ++ind;
    BIT bit(ind);
    while (height.size()) {
        for (auto &x : height) {
            int cnt = bit.query(mp[x.first] - 1);
            if (cnt + x.second[0] == ans.size()) {
                bit.update(mp[x.first], 1);
                ans.push_back({x.first, x.second[0]});
                x.second.erase(x.second.begin());
                if (!x.second.size()) height.erase(height.find(x.first));
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
