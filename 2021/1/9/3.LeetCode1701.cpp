/*************************************************************************
	> File Name: 3.LeetCode1701.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月09日 星期六 00时59分04秒
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
    int arrvial;
    int cost_time;
    Node() = default;
    Node(int arrvial, int cost_time) : arrvial(arrvial), cost_time(cost_time) {}
    bool operator<(const struct Node &a) const {
        return this->arrvial > a.arrvial;
    }
};

double averageWaitingTime(vector<vector<int>>& customers) {
    int clock = 0;
    double wait_time = 0;
    priority_queue<Node> que;
    for (auto &x : customers) que.push(Node(x[0], x[1]));
    clock = que.top().arrvial;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.arrvial <= clock) {
            clock += temp.cost_time;
            wait_time += clock - temp.arrvial;
        } else {
            clock = temp.arrvial + temp.cost_time;
            wait_time += clock - temp.arrvial;
        }
    }
    return wait_time / customers.size();
}

int main() {
    return 0;
}
