/*************************************************************************
	> File Name: 5.LeetCode5743.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 22时46分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int ind;
    int val;
    Node() = default;
    Node(int ind, int val) : ind(ind), val(val) {}
    bool operator<(const struct Node &a) const {
        return this->val == a.val ? this->ind > a.ind : this->val < a.val;
    }
};

vector<int> memLeak(int memory1, int memory2) {
    priority_queue<Node> que;
    que.push(Node(1, memory1));
    que.push(Node(2, memory2));
    int ind = 1;
    vector<int> ans(3);
    while (1) {
        auto temp = que.top();
        que.pop();
        if (ind > temp.val) {
            ans[0] = ind;
            ans[temp.ind] = temp.val;
            temp = que.top();
            ans[temp.ind] = temp.val;
            break;
        }
        temp.val -= ind;
        que.push(temp);
        ind++;
    }
    return ans;
}

int main() {
    int x, y;
    cin >> x >> y;
    auto ans = memLeak(x, y);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
