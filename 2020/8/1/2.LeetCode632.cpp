/*************************************************************************
	> File Name: 2.LeetCode632.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 09时57分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct Node {
    int ind_1, ind_2, val;

    Node() = default;

    Node(int ind_1, int ind_2, int val) : ind_1(ind_1), ind_2(ind_2), val(val) {}

    ~Node() = default;

    bool operator<(const Node &a) const {
        return this->val > a.val;
    }
};

struct Interval {
    int left, right;

    Interval() = default;

    Interval(int left, int right) : left(left), right(right) {}

    ~Interval() = default;

    bool operator<(const Interval &a) const {
        if ((this->right - this->left) == (a.right - a.left)) 
            return this->left > a.left;
        return (this->right - this->left) > (a.right - a.left);
    }
};


vector<int> smallestRange(vector<vector<int>>& nums) {
    int mmax = INT32_MIN;
    priority_queue<Node> que;
    priority_queue<Interval> interval;
    for (int i = 0; i < nums.size(); i++) {
        que.push((Node) {i, 0, nums[i][0]});
        mmax = max(mmax, nums[i][0]);
    }
    while (1) {
        Node tmp = que.top();
        que.pop();
        interval.push((Interval) {tmp.val, mmax});
        if (tmp.ind_2 + 1 == nums[tmp.ind_1].size()) break;
        que.push((Node) {tmp.ind_1, tmp.ind_2 + 1, nums[tmp.ind_1][tmp.ind_2 + 1]});
        mmax = max(mmax, nums[tmp.ind_1][tmp.ind_2 + 1]);
    }
    vector<int> ret(2, 0);
    ret[0] = interval.top().left, ret[1] = interval.top().right;
    return ret;
}

int main() {
    return 0;
}
