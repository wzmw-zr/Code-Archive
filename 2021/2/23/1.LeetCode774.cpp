/*************************************************************************
	> File Name: 1.LeetCode774.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月23日 星期二 00时08分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

double minmaxGasDist(vector<int>& stations, int k) {
    int n = stations.size();
    vector<double> positions(n, 0.0);
    for (int i = 0; i < n; i++) positions[i] = stations[i];
    double l = 0.0, r = positions[1] - positions[0], eps = 0.000001;
    for (int i = 0; i < n - 1; i++) r = max(r, positions[i + 1] - positions[i]);
    while (r - l >= eps) {
        double mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) cnt += (positions[i + 1] - positions[i] - eps) / mid;
        if (cnt > k) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    return 0;
}
