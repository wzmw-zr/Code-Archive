/*************************************************************************
	> File Name: 7.BIT.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 15时13分02秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;

    BIT(int _n) : n(_n), tree(_n + 1, 0) {}

    static constexpr int lowbit(int x) { return x & -x; };

    void add(int ind, int d) {
        while (ind <= n) {
            tree[ind] += d;
            ind += lowbit(ind);
        }
    }  

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

int main() {
    return 0;
}
