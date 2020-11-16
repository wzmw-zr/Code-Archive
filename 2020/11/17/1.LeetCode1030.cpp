/*************************************************************************
	> File Name: 1.LeetCode1030.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月17日 星期二 00时06分44秒
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
    int x, y, dis;
    Node() = default;
    Node(int x, int y, int dis = 0) : x(x), y(y), dis(dis) {}

    bool operator<(const struct Node &a) const {
        return this->dis < a.dis;
    }
};

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<Node> points;
    vector<vector<int>> ans;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            points.push_back({i, j, abs(i - r0) + abs(j - c0)});
        }
    }
    sort(points.begin(), points.end());
    for (auto &x : points) ans.push_back({x.x, x.y});
    return ans;
}
 
int main() {
    int R, C, r0, c0;
    cin >> R >> C >> r0 >> c0;
    auto ans = allCellsDistOrder(R, C, r0, c0);
    for (auto &x : ans) cout << x[0] << " " << x[1] << endl; 
    return 0;
}
