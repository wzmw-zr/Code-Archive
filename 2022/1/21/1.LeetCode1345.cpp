/*************************************************************************
	> File Name: 1.LeetCode1345.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月21日 星期五 22时07分24秒
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

struct Node {
    int idx;
    int step;

    Node() = default;
    Node(int idx, int step) : idx(idx), step(step) {}

    bool operator<(const struct Node &that) const {
        return this->step == that.step ? this->idx < that.idx : this->step > that.step;
    }
};

int minJumps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(arr[i])) mp[arr[i]] = vector<int>();
        mp[arr[i]].push_back(i);
    }
    vector<int> check(n, 0);
    priority_queue<Node> que;
    que.push(Node(0, 0));
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        if (temp.idx == n - 1) return temp.step;
        if (check[temp.idx]) continue;
        check[temp.idx] = 1;
        if (temp.idx > 0) {
            if (!check[temp.idx - 1]) {
                que.push(Node(temp.idx - 1, temp.step + 1));
            }
        }
        if (temp.idx < n - 1) {
            if (!check[temp.idx + 1]) {
                que.push(Node(temp.idx + 1, temp.step + 1));
            }
        }
        for (int ind : mp[arr[temp.idx]]) {
            if (check[ind]) continue;
            que.push(Node(ind, temp.step + 1));
        }
        mp[arr[temp.idx]].clear();
    }
    return -1;
}

int main() {
    return 0;
}
