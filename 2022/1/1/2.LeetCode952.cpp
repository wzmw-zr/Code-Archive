/*************************************************************************
	> File Name: 2.LeetCode952.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月01日 星期六 15时13分46秒
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

const int MAX_N = 1e5;

struct UnionSet {
    int n;
    vector<int> fa;
    vector<int> cnt;

    UnionSet() = default;
    UnionSet(int n) : n(n), fa(vector<int>(n + 10)), cnt(vector<int>(n + 10, 0)) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }

    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    
    void merge(int a, int b) {
        int x = get(a);
        int y = get(b);
        if (x == y) return ;
        fa[x] = y;
        cnt[y] += cnt[x];
    }

    int get_size(int x) {
        return cnt[get(x)];
    }
};

int largestComponentSize(vector<int>& nums) {
    vector<int> min_divisor(MAX_N + 10, -1);
    min_divisor[0] = min_divisor[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (min_divisor[i] != -1) continue;
        for (int j = 1; i * j <= MAX_N; j++) {
            if (min_divisor[i * j] == -1) min_divisor[i * j] = i;
        }
    }
    UnionSet u(MAX_N);
    for (int x : nums) u.cnt[x]++;
    for (int x : nums) {
        int t = x;
        while (t != 1) {
            u.merge(x, min_divisor[t]);
            t /= min_divisor[t];
        }
    }
    int mmax = 1;
    for (int i = 1; i <= MAX_N; i++) mmax = max(mmax, u.get_size(i));
    return mmax;
}

int main() {
    return 0;
}
