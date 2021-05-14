/*************************************************************************
	> File Name: 3.LeetCode907.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 01时18分34秒
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

const long MOD = 1e9 + 7;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<long> left(n, -1);
    vector<long> right(n, n);
    stack<long> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        long temp = ((i - left[i]) * (right[i] - i) % MOD) * (long) arr[i] % MOD;
        ans = (ans + temp) % MOD;
    }
    return ans;
}

int main() {
    return 0;
}
