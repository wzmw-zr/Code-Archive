/*************************************************************************
	> File Name: 2.LeetCode5736.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月18日 星期日 10时36分38秒
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

struct Task {
    int id;
    long start;
    long len;
    Task() = default;
    Task(int id, int start, int len) : id(id), start(start), len(len) {}
    Task(int id, long start, long len) : id(id), start(start), len(len) {}
    bool operator<(const struct Task &a) const {
        return this->len == a.len ? this->id > a.id : this->len > a.len;
    }
};

struct Node {
    int id;
    long start;
    long len;
    Node() = default;
    Node(int id, int start, int len) : id(id), start(start), len(len) {}
    bool operator<(const struct Node &a) const {
        return this->start == a.start ? this->len < a.len : this->start < a.start;
    }
};

vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<Node> nodes;
    for (int i = 0; i < n; i++) nodes.push_back(Node(i, tasks[i][0], tasks[i][1]));
    sort(nodes.begin(), nodes.end());
    priority_queue<Task> que;
    long t = 0;
    vector<int> ans;
    for (int i = 0; i < n; ) {
        if (que.empty()) {
            int s = nodes[i].start;
            while (i < n && nodes[i].start == s) {
                que.push(Task(nodes[i].id, nodes[i].start, nodes[i].len));
                i++;
            }
        }
        Task temp = que.top();
        cout << temp.id << " " << temp.start << " " << temp.len << endl;
        que.pop();
        t = max(t, temp.start);
        ans.push_back(temp.id);
        while (i < n && nodes[i].start <= t + temp.len) {
            que.push(Task(nodes[i].id, nodes[i].start, nodes[i].len));
            i++;
        }
        t += temp.len;
    }
    while (!que.empty()) {
        Task temp = que.top();
        que.pop();
        ans.push_back(temp.id);
    }
    return ans;
}

int main() {
    return 0;
}
