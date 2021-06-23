/*************************************************************************
	> File Name: 1.LeetCode149.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月24日 星期四 00时11分04秒
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

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                long x1 = points[j][0] - points[i][0];
                long y1 = points[j][1] - points[i][1];
                long x2 = points[k][0] - points[i][0];
                long y2 = points[k][1] - points[i][1];
                if ((x1 * y2) == (x2 * y1)) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main() {
    return 0;
}
