/*************************************************************************
	> File Name: 8.LeetCode952.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 23时09分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

//   TLE 

#define MAX_N 100010

vector<int> prime(MAX_N, 0);
vector<vector<int>> factor(MAX_N, vector<int>(0));

void init() {
    for (int i = 2; i <= 100000; i++) {
        if (prime[i]) continue;
        factor[i].push_back(i);
        for (int j = 1; i * j <= 100000; j++) {
            prime[i * j] = 1;
            factor[i * j].push_back(i);
        }
    }
}

struct UnionSet {
    int n;
    vector<int> fa;
    vector<int> cnt;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n), cnt(n, 0) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
        cnt[b] += cnt[a];
    }
};

int largestComponentSize(vector<int>& A) {
    init();
    UnionSet u(MAX_N);
    for (auto &x : A) {
        for (auto &y : factor[x]) u.merge(x, y);
        u.cnt[u.get(x)]++;
    }
    int ans = 0;
    for (int &x : u.cnt) ans = max(ans, x);
    return ans;
}

int main() {
    return 0;
}
