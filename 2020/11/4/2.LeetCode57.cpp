/*************************************************************************
	> File Name: 2.LeetCode57.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 00时28分43秒
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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int i = 0;
    for (i = 0; i < intervals.size() - 1; ) {
        if (intervals[i][1] < intervals[i + 1][0]) {
            ans.push_back(intervals[i++]);
        } else {
            int left = intervals[i][0], right = max(intervals[i][1], intervals[i + 1][1]);
            while (i < intervals.size() && intervals[i][0] <= right) {
                right = max(right, intervals[i++][1]);
            }
            ans.push_back(vector<int>{left, right});
        }
    } 
    if (i == intervals.size() - 1) ans.push_back(intervals[i]);
    return ans;
}

int main() {
    vector<int> newInterval(2), interval(2);
    vector<vector<int>> intervals;
    cin >> newInterval[0] >> newInterval[1];
    while (cin >> interval[0] >> interval[1]) {
        intervals.push_back(interval);
    }
    auto ans = insert(intervals, newInterval);
    for (auto &x : ans) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
