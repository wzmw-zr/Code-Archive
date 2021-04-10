/*************************************************************************
	> File Name: 1.LeetCode264.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月11日 星期日 00时03分47秒
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

int nthUglyNumber(int n) {
    unordered_set<long> check;
    set<long> st;
    priority_queue<long, vector<long>, greater<long>> que;
    que.push(1);
    st.insert(1);
    check.insert(1);
    long num[3] = {2, 3, 5};
    while (!que.empty()) {
        long temp = que.top();
        que.pop();
        st.insert(temp);
        for (int i = 0; i < 3; i++) {
            if (check.count(temp * num[i])) continue;
            que.push(temp * num[i]);
            check.insert(temp * num[i]);
        }
        if (st.size() >= n) break;
    }
    vector<long> nums;
    for (long x : st) nums.push_back(x);
    return nums[n - 1];
}

int main() {
    int n;
    cin >> n;
    cout << nthUglyNumber(n) << endl;
    return 0;
}
