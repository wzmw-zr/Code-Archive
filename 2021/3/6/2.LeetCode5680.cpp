/*************************************************************************
	> File Name: 2.LeetCode5680.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月06日 星期六 22时30分52秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int min_dis = INT32_MAX, ans = -1;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        if (x == points[i][0] || y == points[i][1]) {
            int dis = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (dis >= min_dis) continue;
            min_dis = dis;
            ans = i;
        }
    }
    return ans;
}

int main() {
    return 0;
}
