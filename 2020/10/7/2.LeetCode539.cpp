/*************************************************************************
	> File Name: 2.LeetCode539.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月07日 星期三 07时31分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int cal_dis(string &time_1, string &time_2) {
    int hour_1 = 0, hour_2 = 0, minute_1 = 0, minute_2 = 0;
    for (int i = 0; i < 2; i++) {
        hour_1 = hour_1 * 10 + time_1[i] - '0';
        hour_2 = hour_2 * 10 + time_2[i] - '0';
    }
    for (int i = 3; i < 5; i++) {
        minute_1 = minute_1 * 10 + time_1[i] - '0';
        minute_2 = minute_2 * 10 + time_2[i] - '0';
    }
    return (hour_2 - hour_1) * 60 + minute_2 - minute_1;
}

int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    for (auto &x : timePoints) cout << x << " ";
    cout << endl;
    int dis = INT32_MAX, len = timePoints.size();
    for (int i = 0; i < len - 1; i++) {
        dis = min(dis, cal_dis(timePoints[i], timePoints[i + 1]));
    }
    dis = min(dis, cal_dis(timePoints[len - 1], timePoints[0]) + 1440);
    return dis;
}

int main() {
    vector<string> timePoints;
    timePoints.push_back("23:59");
    timePoints.push_back("00:00");
    cout << findMinDifference(timePoints) << endl;
    return 0;
}
