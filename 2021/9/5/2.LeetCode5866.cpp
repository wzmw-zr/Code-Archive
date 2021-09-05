/*************************************************************************
	> File Name: 2.LeetCode5866.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月05日 星期日 10时55分35秒
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

struct UnionSet {
    vector<int> fa;
    int cnt;

    UnionSet() = default;
    UnionSet(int n) : fa(vector<int>(n)), cnt(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    int find(int n) {
        return fa[n] = n == fa[n] ? n : find(fa[n]);
    }

    void merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return ;
        fa[x] = y;
        cnt--;
    }
};

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

bool gcdSort(vector<int>& nums) {
    int n = nums.size();
    UnionSet u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(nums[i], nums[j]) == 1) continue;
            u.merge(i, j);
        }
    }
    return u.cnt == 1;
}

int main() {
    return 0;
}
