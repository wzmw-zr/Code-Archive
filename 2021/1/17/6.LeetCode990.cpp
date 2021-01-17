/*************************************************************************
	> File Name: 6.LeetCode990.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月17日 星期日 22时01分34秒
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

struct UnionSet {
    int n;
    vector<int> fa;
    vector<int> val;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n), val(n, 0) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]] + 2) % 2;
        return fa[x] = root;
    }
    bool merge(int x, int y, int value) {
        int a = get(x);
        int b = get(y);
        if (a == b) {
            if (((val[x] - val[y] + value + 2) % 2) == 0) return true;
            return false;
        }
        fa[a] = b;
        val[a] = (value + val[y] - val[x] + 2) % 2;
        return true;
    }
};

bool equationsPossible(vector<string>& equations) {
    UnionSet u(26);
    for (auto &s : equations) {
        int value = s[1] == '=' ? 0 : 1;
        if (u.merge(s[0] - 'a', s[3] - 'a', value)) continue;
        return false;
    }
    return true;
}

int main() {
    return 0;
}
