/*************************************************************************
	> File Name: 2.LeetCode786.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月29日 星期一 08时42分32秒
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


vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    using PII = pair<int, int>;
    auto cmp = [&](PII &a, PII &b) {
        return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> que(cmp);
    for (int i = 1; i < n; i++) que.push(PII(0, i));
    vector<int> ans;
    while (k) {
        auto temp = que.top();
        que.pop();
        if (!(--k)) return {arr[temp.first], arr[temp.second]};
        if ((++temp.first) == temp.second) continue;
        que.push(temp);
    }
    return {};
}

int main() {
    return 0;
}
