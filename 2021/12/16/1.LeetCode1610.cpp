/*************************************************************************
	> File Name: 1.LeetCode1610.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月16日 星期四 08时27分26秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int find_first(vector<double> &angles, double angle) {
    int l = 0, r = angles.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (angles[mid] >= angle) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_last(vector<double> &angles, double angle) {
    int l = 0, r = angles.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (angles[mid] <= angle) l = mid;
        else r = mid - 1;
    }
    return l;
}

int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    int same = 0;
    vector<double> angles;
    for (auto point : points) {
        if (point == location) {
            same++;
            continue;
        }
        double x = point[0] - location[0];
        double y = point[1] - location[1];
        double temp = (acos(x / pow(x * x + y * y, 0.5)) / M_PI) * 180;
        if (y < 0) temp = 360.0 - temp;
        angles.push_back(temp);
    }
    int n = angles.size();
    sort(angles.begin(), angles.end());
    for (int i = 0; i < n; i++) angles.push_back(angles[i] + 360);
    for (int i = 0; i < n; i++) angles.push_back(angles[i] + 720);
    int mmax = 0;
    for (int i = n; i < 2 * n; i++) {
        int left = find_first(angles, angles[i] - angle);
        int right = find_last(angles, angles[i] + angle);
        mmax = max(mmax, i - left + 1);
        mmax = max(mmax, right - i + 1);
    }
    return mmax + same;
}

int main() {
    return 0;
}
