/*************************************************************************
	> File Name: 1.LeetCode650.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月19日 星期日 08时08分07秒
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

struct Node {
    int val;
    int num;
    int step;

    Node() = default;
    Node(int val, int num, int step) : val(val), num(num), step(step) {}

    bool operator<(const struct Node &that) const {
        if (this->val == that.val) {
            if (this->step == that.step) return this->num > that.num;
            return this->step > that.step;
        } 
        return this->val > that.val;
    }
};

int minSteps(int n) {
    vector<vector<int>> check(n + 1, vector<int>(n + 1, 0));
    priority_queue<Node> que;
    que.push(Node(1, 0, 0));
    check[1][0] = 1;
    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        if (temp.val == n) return temp.step;
        if (temp.val + temp.num <= n && !check[temp.val + temp.num][temp.num]) {
            check[temp.val + temp.num][temp.num] = 1;
            que.push(Node(temp.val + temp.num, temp.num, temp.step + 1));
        }
        if (!check[temp.val][temp.val]) {
            check[temp.val][temp.val] = 1;
            que.push(Node(temp.val, temp.val, temp.step + 1));
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n) << endl;
    return 0;
}
