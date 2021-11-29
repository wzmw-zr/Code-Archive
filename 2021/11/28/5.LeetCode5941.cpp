/*************************************************************************
	> File Name: 5.LeetCode5941.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月28日 星期日 10时49分31秒
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

using PII = pair<int, int>;

struct Node {
    int id;
    vector<PII> next;

    Node() = default;
};

struct Info {
    int id;
    int time;

    Info() = default;
    Info(int id, int time) : id(id), time(time) {}

    bool operator<(const struct Info &that) const {
        return this->time > that.time;
    }
};

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) nodes[i].id = i;
    for (auto meeting : meetings) {
        nodes[meeting[0]].next.push_back(PII(meeting[2], meeting[1]));
        nodes[meeting[1]].next.push_back(PII(meeting[2], meeting[0]));
    }
    vector<int> check(n, 0);
    priority_queue<Info> que;
    que.push(Info(0, 0));
    que.push(Info(firstPerson, 0));
    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        if (check[temp.id]) continue;
        check[temp.id] = 1;
        for (auto e : nodes[temp.id].next) {
            if (e.first < temp.time) continue;
            if (check[e.second]) continue;
            que.push(Info(e.second, e.first));
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (check[i]) ans.push_back(i);
    }
    return ans;
}

int main() {
    return 0;
}
