/*************************************************************************
	> File Name: 1.LeetCode528.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月30日 星期一 08时38分45秒
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
#include <ctime>
using namespace std;

struct BIT {
    int n;
    vector<int> nums;

    BIT() = default;
    BIT(int n) : n(n), nums(vector<int>(n + 1, 0)) {}

    int lowbit(int x) { return x & -x; }

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
};

class Solution {
public:
    BIT bit;
    vector<int> w;
    int sum;

    Solution(vector<int>& w) : w(w), bit((int) w.size()), sum(0) {
        srand(time(0));
        int n = w.size();
        for (int i = 0; i < n; i++) {
            bit.update(i + 1, w[i]);
            sum += w[i];
        }
    }

    int pickIndex() {
        int num = (rand() % sum) + 1;
        int l = 1, r = w.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (bit.query(mid) < num) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};

int main() {
    return 0;
}
