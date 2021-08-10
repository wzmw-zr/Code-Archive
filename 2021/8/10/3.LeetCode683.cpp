/*************************************************************************
	> File Name: 3.LeetCode683.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月10日 星期二 10时25分12秒
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

struct BIT {
    int n;
    vector<int> nums;

    BIT() = default;
    BIT(int n) : n(n), nums(vector<int>(n + 1, 0)) {}

    int lowbit(int n) { return n & -n; }

    void update(int ind, int val) {
        while (ind <= n) {
            nums[ind] += val;
            ind += lowbit(ind);
        }
    }

    int query(int ind) {
        int ans = 0;
        while (ind) {
            ans += nums[ind];
            ind -= lowbit(ind);
        }
        return ans;
    }

    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int kEmptySlots(vector<int>& bulbs, int k) {
    int n = bulbs.size();
    BIT bit(n);
    for (int i = 0; i < n; i++) {
        bit.update(bulbs[i], 1);
        if ((bulbs[i] >= k + 2) && (bit.query(bulbs[i] - k - 1, bulbs[i]) == 2) && (bit.query(bulbs[i] - k, bulbs[i]) == 1)) return i + 1;
        if ((bulbs[i] <= (n - k - 1)) && (bit.query(bulbs[i], bulbs[i] + k + 1) == 2) && (bit.query(bulbs[i], bulbs[i] + k) == 1)) return i + 1;
    }
    return -1;
}

int main() {
    return 0;
}
