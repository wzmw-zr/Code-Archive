/*************************************************************************
	> File Name: 1.LeetCode447.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月13日 星期一 10时01分58秒
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
#include <cmath>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    int n = points.size();
    vector<unordered_map<int, int>> pos(n, unordered_map<int, int>());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dis = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
            printf("(%d, %d), (%d, %d), dis = %d\n", points[i][0], points[i][1], points[j][0], points[j][1], dis);
            pos[i][dis]++;
            pos[j][dis]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto &&[dis, cnt] : pos[i]) ans += cnt * (cnt - 1);
    }
    for (int i = 0; i < n; i++) {
        printf("i = %d, ", i);
        for (auto &&[dis, cnt] : pos[i]) printf("(dis = %d, cnt = %d), ", dis, cnt);
        printf("\n");
    }
    return ans;
}

int main() {
    return 0;
}
