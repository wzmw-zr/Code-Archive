/*************************************************************************
	> File Name: 1.LeetCode313.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月09日 星期一 00时05分43秒
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

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<long> nums;
    for (int x : primes) nums.push_back(x);
    set<long> st;
    priority_queue<long, vector<long>, greater<long>> que;
    que.push(static_cast<long>(1));
    while (st.size() < n) {
        long t = que.top();
        que.pop();
        if (!st.count(t)) {
            for (long x : nums) {
                if (x * t > static_cast<long>(INT32_MAX)) break;
                if (st.count(x * t)) continue;
                que.push(x * t);
            }
            st.insert(t);
        }
    }
    return *st.rbegin();
}

int main() {
    int n, m;
    cin >> n;
    vector<int> primes;
    while (cin >> m) primes.push_back(m);
    cout << nthSuperUglyNumber(n, primes) << endl;
    return 0;
}
