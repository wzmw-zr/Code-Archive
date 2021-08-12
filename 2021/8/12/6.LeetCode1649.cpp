/*************************************************************************
	> File Name: 6.LeetCode1649.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月12日 星期四 16时32分33秒
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

    BIT(int n) : n(n), nums(vector<int>(n, 0)) {}
    
    int lowbit(int x) { return x & -x; };

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

    void update(int ind, int val) {
        while (ind < n) {
            nums[ind] += val;
            ind += lowbit(ind);
        }
    }
};
    
int createSortedArray(vector<int>& instructions) {
    const long MOD = 1e9 + 7;
    long ans = 0;
    BIT bit(1e5 + 10);
    for (int x : instructions) {
        ans += 1L * min(bit.query(1, x), bit.query(x + 2, 1e5 + 1));
        ans %= MOD;
        bit.update(x + 1, 1);
    }
    return ans;
}

int main() {
    return 0;
}
