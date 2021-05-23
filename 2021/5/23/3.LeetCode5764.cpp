/*************************************************************************
	> File Name: 3.LeetCode5764.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月23日 星期日 10时38分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool check(vector<int> &dist, int speed, double hour) {
    double v = speed;
    double cost = 0.0;
    int n = dist.size();
    for (int i = 0; i < n; i++) {
        if (i < (n - 1)) 
            cost += dist[i] / speed + ((dist[i] % speed) ? 1 : 0);
        else 
            cost += dist[i] * 1.0 / v;
    }
    return cost <= hour;
}

int minSpeedOnTime(vector<int>& dist, double hour) {
    int l = 1, r = 1e7;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(dist, mid, hour)) r = mid;
        else l = mid + 1;
    }
    return check(dist, l, hour) ? l : -1;
}

int main() {
    return 0;
}
