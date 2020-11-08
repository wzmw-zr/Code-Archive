/*************************************************************************
	> File Name: 5.LeetCode5563.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 10时57分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

const long MOD = 1e9 + 7;

struct Node {
    long number, times;
    Node() = default;
    Node(long n) : number(n), times(1) {}
    Node(long n, long t) : number(n), times(t) {}
    Node(int n) : number(n), times(1) {}
    Node(int n, int t) : number(n), times(t) {}

    bool operator<(const Node &a) const {
        return this->number < a.number;
    }
};

int maxProfit(vector<int>& inventory, int orders) {
    long ans = 0;
    priority_queue<Node> que;
    for (int &x : inventory) que.push(Node(x));
    while (orders) {
        Node temp = que.top();
        que.pop();
        if (que.empty()) {
            long cnt = orders / temp.times;
            long rest = orders % temp.times;
            ans += (2 * temp.number - cnt + 1) * cnt * temp.times / 2;
            ans += rest * temp.number;
            ans %= MOD;
            orders = 0;
        } else {
            Node next = que.top();
            long cnt = (temp.number - next.number) * temp.times;
            if (cnt < orders) {
                ans += (temp.number + next.number + 1) * cnt / 2;
                ans %= MOD;
                orders -= cnt;
                que.pop();
                next.times += temp.times;
                que.push(next);
            } else {
                long cnt = orders / temp.times;
                long rest = orders % temp.times;
                ans += (2 * temp.number - cnt + 1) * cnt * temp.times / 2;
                ans += rest * temp.number;
                ans %= MOD;
                orders = 0;
            }
        }
    }
    return ans;
}

int main() {
    int orders, num;
    vector<int> inventory;
    cin >> orders;
    while (cin >> num) inventory.push_back(num);
    cout << maxProfit(inventory, orders) << endl;
    return 0;
}
