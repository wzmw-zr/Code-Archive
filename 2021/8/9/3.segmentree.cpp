/*************************************************************************
	> File Name: 3.segmentree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月09日 星期一 15时51分28秒
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

struct SegTree {
    int _left;
    int _right;
    vector<int> nums;
    vector<int> lazy;

    SegTree(int n) : nums(vector<int>(4 * n + 10, 0)), lazy(vector<int>(2 * n + 10, 0)), _left(1), _right(n) {}

    void push_down(int l, int r, int ind) {
        if (l == r) return ;
        int mid = (l + r) / 2;
        nums[ind * 2] += lazy[ind] * (mid - l + 1);
        nums[ind * 2 + 1] += lazy[ind] * (r - mid);
        lazy[ind * 2] += lazy[ind];
        lazy[ind * 2 + 1] += lazy[ind];
        lazy[ind] = 0;
    }

    int update(int s, int t, int l, int r, int ind, int val) {
        if (t < l || s > r) return 0;
        if (l >= s && r <= t) {
            nums[ind] += val * (r - l + 1);
            lazy[ind] += val;
            return val * (r - l + 1);
        }
        push_down(l, r, ind);
        int mid = (l + r) / 2;
        int temp = 0;
        if (s <= mid) temp += update(s, t, l, mid, ind * 2, val);
        if (t > mid) temp += update(s, t, mid + 1, r, ind * 2 + 1, val);
        nums[ind] += temp;
        return temp;
    }

    void update(int l, int r, int val) {
        update(l, r, _left, _right, 1, val);
    }

    int query(int s, int t, int l, int r, int ind) {
        if (t < l || s > r) return 0;
        if (l >= s && r <= t) return nums[ind];
        push_down(l, r, ind);
        int mid = (l + r) / 2;
        int res = 0;
        if (s <= mid) res += query(s, t, l, mid, ind * 2);
        if (t > mid) res += query(s, t, mid + 1, r, ind * 2 + 1);
        return res;
    }

    int query(int l, int r) {
        return query(l, r, _left, _right, 1);
    }
};

int main() {
    return 0;
}
