/*************************************************************************
	> File Name: 3.LeetCode1620.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月11日 星期三 22时12分51秒
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

struct Node {
    int x, y, val;
    Node() = default;
    Node(int x, int y, int val = 0) : x(x), y(y), val(val) {}

    int operator-(const Node &a) const {
        return abs(this->x - a.x) + abs(this->y - a.y);
    }

    bool operator<(const Node &a) const {
        return this->val == a.val ? (this->x == a.x ? this->y < a.y : this->x < a.x) : this->val > a.val;
    }

    bool operator==(const Node &a) const {
        return this->x == a.x && this->y == a.y;
    }
};

void update(vector<int> &coordinate, int &radius, map<Node, int> &mp) {
    int x = coordinate[0], y = coordinate[1];
    int q = coordinate[2];
    Node core(x, y);
    mp[core] += q;
    for (int i = 1; i <= radius; i++) {
        Node t1(x + i, y), t2(x - i, y), t3(x, y + i), t4(x, y - i);
        mp[t1] += q / (core - t1 + 1);
        mp[t2] += q / (core - t2 + 1);
        mp[t3] += q / (core - t3 + 1);
        mp[t4] += q / (core - t4 + 1);
    }
    for (int i = 1; i <= radius; i++) {
        for (int j = 1; j <= radius - i; j++) {
            Node t1(x + i, y + j), t2(x + i, y - j), t3(x - i, y + j), t4(x - i, y - j);
            mp[t1] += q / (core - t1 + 1);
            mp[t2] += q / (core - t2 + 1);
            mp[t3] += q / (core - t3 + 1);
            mp[t4] += q / (core - t4 + 1);
        }
    }
}

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    map<Node, int> mp;
    for (auto &x : towers) update(x, radius, mp);
    vector<Node> nodes;
    for (auto x : mp) {
        Node temp(x.first.x, x.first.y, x.second);
        nodes.push_back(temp);
    }
    sort(nodes.begin(), nodes.end());
    //for (auto &x : nodes) cout << x.x << " " << x.y << " " << x.val << endl;
    return {nodes[0].x, nodes[0].y};
}

int main() {
    int radius, x, y, q;
    vector<vector<int>> towers;
    cin >> radius;
    while (cin >> x >> y >> q) towers.push_back({x, y, q});
    auto ans = bestCoordinate(towers, radius);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
