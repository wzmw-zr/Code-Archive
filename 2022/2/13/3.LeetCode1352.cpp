/*************************************************************************
	> File Name: 3.LeetCode1352.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月13日 星期日 00时19分57秒
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

struct SegTree {
    int n;
    vector<int> nums;
    vector<int> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), nums(vector<int>(4 * n + 10, 1)), lazy(vector<int>(4 * n + 10, 1)) {}

    void push_down(int ind, int l, int r) {
        if (l == r) {
            return ;
        }
        lazy[ind * 2 + 1] *= lazy[ind];
        lazy[ind * 2 + 2] *= lazy[ind];
        nums[ind * 2 + 1] *= lazy[ind];
        nums[ind * 2 + 2] *= lazy[ind];
        lazy[ind] = 1;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) {
            return ;
        }
        nums[ind] = nums[ind * 2 + 1] * nums[ind * 2 + 2];
    }

    void update(int ind, int l, int r, int s, int t, int val) {
        if (s > r || t < l) {
            return ;
        }
        if (l >= s && r <= t) {
            nums[ind] *= val;
            lazy[ind] *= val;
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) {
            update(ind * 2 + 1, l, mid, s, t, val);
        }
        if (t >= mid + 1) {
            update(ind * 2 + 2, mid + 1, r, s, t, val);
        }
        push_up(ind, l, r);
    }

    void update(int left, int right, int val) {
        update(0, 0, n, left, right, val);
    }

    int query(int ind, int l, int r, int s, int t) {
        if (s > r || t < l) {
            return 1;
        }
        if (l >= s && r <= t) {
            return nums[ind];
        }
        push_down(ind, l, r);
        int ans = 1;
        int mid = (l + r) / 2;
        if (s <= mid) {
            ans *= query(ind * 2 + 1, l, mid, s, t);
        }
        if (t >= mid + 1) {
            ans *= query(ind * 2 + 2, mid + 1, r, s, t);
        }
        push_up(ind, l, r);
        return ans;
    }

    int query(int left, int right) {
        return query(0, 0, n, left, right);
    }
};

class ProductOfNumbers {
public:
    int ind;
    SegTree segtree;

    ProductOfNumbers() : ind(0), segtree(SegTree(40010)) {
    }

    void add(int num) {
        segtree.update(ind, ind, num);
        ind++;
    }

    int getProduct(int k) {
        return segtree.query(ind - k, ind - 1);
    }
};

int main() {
    return 0;
}
