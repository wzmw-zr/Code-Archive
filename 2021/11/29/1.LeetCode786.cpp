/*************************************************************************
	> File Name: 1.LeetCode786.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月29日 星期一 08时03分05秒
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
    vector<PII> scores(n * (n - 1) / 2);
    int ind = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) scores[ind++] = PII(arr[i], arr[j]);
    }
    auto cmp = [](PII &a, PII &b) {
        return a.first * b.second < b.first * a.second;
    };
    sort(scores.begin(), scores.end(), cmp);
    return {scores[k - 1].first, scores[k - 1].second};
}

int main() {
    return 0;
}
