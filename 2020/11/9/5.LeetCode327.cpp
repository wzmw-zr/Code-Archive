/*************************************************************************
	> File Name: 5.LeetCode327.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 15时22分52秒
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
    int left, right, val, flag;
    Node *lchild, *rchild;
    Node() = default;
    Node(int left, int right, int val = 0) : left(left), right(right), val(val), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
    Node *__root;

    SegTree() = default;
    SegTree(int left, int right) {
        __root = build(left, right);
    }

    Node *build(int left, int right) {
        Node *root = new Node(left, right);
        if (left == right) return root;
        int mid = (left + right) / 2;
        root->lchild = build(left, mid);
        root->rchild = build(mid + 1, right);
        return root;
    }

    void add(int ind, int val) {
        __add(__root, ind, val);
    }

    void __add(Node *root, int ind, int val) {
        if (!root) return ;
        if (root->left == root->right) {
            root->val += val;
            return ;
        }
        int mid = (root->left + root->right) / 2;
        if (ind <= mid) __add(root->lchild, ind, val);
        else __add(root->rchild, ind, val);
        root->val += val;
    }

    int query(int left, int right) {
        return __query(__root, left, right);
    }

    int __query(Node *root, int left, int right) {
        if (!root) return 0;
        if (root->right < left || root->left > right) return 0;
        if (root->left >= left && root->right <= right) return root->val;
        return __query(root->lchild, left, right) + __query(root->rchild, left, right);
    }
};

int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long> preSum(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) preSum[i + 1] = preSum[i] + nums[i];
    set<long> numbers;
    for (long &x : preSum) {
        numbers.insert(x);
        numbers.insert(x - upper);
        numbers.insert(x - lower);
    }
    int id = 0;
    unordered_map<long, int> mp;
    for (long x : numbers) mp[x] = ++id;
    int ans = 0;
    SegTree segtree(1, numbers.size());
    for (long &x : preSum) {
        int left = mp[x - upper], right = mp[x - lower];
        ans += segtree.query(left, right);
        segtree.add(mp[x], 1);
    }
    return ans;
}

int main() {
    int lower, upper, x;
    vector<int> nums;
    cin >> lower >> upper;
    while (cin >> x) nums.push_back(x);
    cout << countRangeSum(nums, lower, upper) << endl;
    return 0;
}
