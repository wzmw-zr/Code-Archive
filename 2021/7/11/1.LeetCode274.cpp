/*************************************************************************
	> File Name: 1.LeetCode274.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月11日 星期日 00时12分56秒
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

int find_left_last(vector<int> &citations, int h) {
    int l = 0, r = citations.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (citations[mid] >= h) l = mid;
        else r = mid - 1;
    }
    return l;
}

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), [](int a, int b){ return a > b; });
    int n = citations.size();
    int mmax = min(citations[0], n);
    int ans = -1;
    for (int h = 0; h <= mmax; h++) {
        if ((find_left_last(citations, h) + 1) >= h) ans = h;
    }
    return ans;
}

int main() {
    return 0;
}
