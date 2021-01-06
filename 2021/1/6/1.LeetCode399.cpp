/*************************************************************************
	> File Name: 1.LeetCode399.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月06日 星期三 07时45分08秒
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
    vector<double> val;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n), val(n, 1) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] *= val[fa[x]];
        fa[x] = root;
        return fa[x];
    }

    void merge(int x, int y, double times) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
        val[a] = val[y] / (times * val[x]);
    } 

    double query(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a - b) return -1.0;
        return val[y] / val[x];
    }
};

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, int> hash;
    int ind = 0;
    for (auto &x : equations) {
        if (!hash.count(x[0])) hash[x[0]] = ind++;
        if (!hash.count(x[1])) hash[x[1]] = ind++;
    }
    UnionSet u(ind);
    for (int i = 0; i < equations.size(); i++) {
        string x = equations[i][0];
        string y = equations[i][1];
        u.merge(hash[x], hash[y], values[i]);
    }
    vector<double> ans;
    for (auto &x : queries) {
        if (!hash.count(x[0]) || !hash.count(x[1])) ans.push_back(-1.0);   
        else ans.push_back(u.query(hash[x[0]],  hash[x[1]]));
    }
    return ans;
}

int main() {
    return 0;
}
