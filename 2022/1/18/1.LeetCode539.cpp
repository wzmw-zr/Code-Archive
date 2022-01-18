/*************************************************************************
	> File Name: 1.LeetCode539.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月18日 星期二 13时50分12秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Time {
    int hour;
    int minute;

    Time() : hour(0), minute(0) {}
    Time(int hour, int minute) : hour(hour), minute(minute) {}
    Time(string time) {
        hour = stoi(time.substr(0, 2));
        minute = stoi(time.substr(3, 2));
    }

    bool operator<(const struct Time &that) const {
        return this->hour == that.hour ? this->minute < that.minute : this->hour < that.hour;
    }

    int operator-(const struct Time &that) const {
        return (this->hour - that.hour) * 60 + (this->minute - that.minute);
    }
};

int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    vector<Time> times;
    for (string &s : timePoints) {
        times.emplace_back(s);
    }
    sort(times.begin(), times.end());
    int ans = INT32_MAX;
    for (int i = 1; i < n; i++) {
        int t = times[i] - times[i - 1];
        ans = min({ans, t, 1440 - t});
    } 
    int t = times[n - 1] - times[0];
    ans = min({ans, t, 1440 - t});
    return ans;
}

int main() {
    return 0;
}
