/*************************************************************************
	> File Name: 1.LeetCode517.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月29日 星期三 22时53分45秒
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

int findMinMoves(vector<int> &machines) {
    int n = machines.size();
    int sum = 0;
    for (int x : machines) sum += x;
    if (sum % n) return -1;
    int avg = sum / n;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] += pre[i] + machines[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, max(0, i * avg - pre[i]) + max(0, (n - i - 1) * avg - (sum - pre[i + 1])));
    }
    return ans;
}

int main() {
    vector<int> machines;
    int n;
    while (cin >> n) machines.push_back(n);
    cout << findMinMoves(machines) << endl;
    return 0;
}
