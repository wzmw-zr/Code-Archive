/*************************************************************************
	> File Name: 2.LeetCode5805.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月24日 星期六 22时33分46秒
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

#define LEFT 0
#define RIGHT 1

struct Node {
    int coord;
    int ind;
    int event;

    Node() = default;
    Node(int coord, int ind, int event) : coord(coord), ind(ind), event(event) {}

    bool operator<(const struct Node &that) const {
        return this->coord == that.coord ? this->event > that.event: this->coord < that.coord;
    }
};

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    vector<Node> points;
    priority_queue<int, vector<int>, greater<int>> que;
    int n = times.size();
    for (int i = 0; i < n; i++) {
        points.push_back(Node{times[i][0], i, LEFT});
        points.push_back(Node{times[i][1], i, RIGHT});
        que.push(i);
    }
    sort(points.begin(), points.end());
    vector<int> chair_id(n);
    for (auto point : points) {
        if (point.event == LEFT) {
            chair_id[point.ind] = que.top();
            que.pop();
        } else {
            que.push(chair_id[point.ind]);
        }
    }
    return chair_id[targetFriend];
}

int main() {
    return 0;
}
