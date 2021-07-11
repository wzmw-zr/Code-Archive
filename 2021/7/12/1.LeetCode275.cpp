/*************************************************************************
	> File Name: 1.LeetCode275.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月12日 星期一 00时03分01秒
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

int find_first(vector<int> &citations, int h) {
    int l = 0, r = (int) citations.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (citations[mid] >= h) r = mid;
        else l = mid + 1;
    }
    return l;
}

int hIndex(vector<int>& citations) {
    int n = citations.size();
    int mmax = min(n, citations[n - 1]);
    int ans = 0;
    for (int h = 0; h <= mmax; h++) {
        int ind = find_first(citations, h);
        if ((n - ind) >= h) ans = h;
    }
    return ans;
}

int main() {
    return 0;
}
