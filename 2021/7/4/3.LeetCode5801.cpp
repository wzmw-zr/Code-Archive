/*************************************************************************
	> File Name: 3.LeetCode5801.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月04日 星期日 10时49分06秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    vector<int> costs(n);
    for (int i = 0; i < n; i++) costs[i] = ceil((double) dist[i] / (double) speed[i]);
    sort(costs.begin(), costs.end());
    for (int i = 0; i < n; i++) {
        if (costs[i] > i) continue;
        return i;
    }
    return n;
}

int main() {
    return 0;
}
