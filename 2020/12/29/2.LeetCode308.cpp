/*************************************************************************
	> File Name: 2.LeetCode308.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月29日 星期二 08时05分29秒
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

struct BIT {
    int n;
    vector<int> nums;
    vector<long> arrs;
    BIT() = default;
    BIT(int n) : n(n), nums(n + 1) {}
    BIT(vector<int> &arr) : n(arr.size()), nums(arr.size() + 1, 0), arrs(arr.size() + 1, 0) {
        for (int i = 0; i < arr.size(); i++) nums[i + 1] = arr[i];
        build();
    }

    constexpr int lowbit(int x) { return x & -x; }

    void build() {
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j <= n) {
                arrs[j] += nums[i];
                j += lowbit(j);
            }
        }
    }

    void update(int ind, int val) {
        int dis = val - nums[++ind];
        nums[ind] = val;
        while (ind <= n) {
            arrs[ind] += dis;
            ind += lowbit(ind);
        }
    }

    long query(int ind) {
        ind++;
        long sum = 0;
        while (ind) {
            sum += arrs[ind];
            ind -= lowbit(ind);
        }
        return sum;
    }
};

class NumMatrix {
public:
    vector<BIT> bits;
    NumMatrix(vector<vector<int>>& matrix) {
        for (auto &x : matrix) bits.push_back(BIT(x));
    }

    void update(int row, int col, int val) {
        bits[row].update(col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        long sum = 0;
        for (int i = row1; i <= row2; i++) sum += bits[i].query(col2) - bits[i].query(col1 - 1);
        return (int) sum;
    }
};

int main() {
    return 0;
}
