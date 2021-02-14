/*************************************************************************
	> File Name: 2.LeetCode1353.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月15日 星期一 00时09分29秒
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
    int start;
    int end;
    Node() = default;
    Node(int start, int end) : start(start), end(end) {}
    bool operator<(const struct Node &a) const {
        return this->end == a.end ? this->start > a.start : this->end > a.end;
    }
}; 

// WA

int maxEvents(vector<vector<int>>& events) {
    priority_queue<Node> que;
    for (auto &event : events) que.push(Node(event[0], event[1]));
    int start_day = 0, cnt = 0;
    while (!que.empty()) {
        while (!que.empty() && que.top().end < start_day) que.pop();
        if (!que.empty()) {
            start_day = max(start_day, que.top().start) + 1;
            que.pop();
            cnt++;
        }
    }
    return cnt;
}

int main() {
    return 0;
}
