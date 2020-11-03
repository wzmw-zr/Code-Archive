/*************************************************************************
	> File Name: 1.LeetCode57.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 00时04分24秒
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
    vector<vector<int>> ans;
    if (intervals.size() == 0 || intervals[0][0] > newInterval[1]) ans.push_back(newInterval); 
    for (int i = 0; i < intervals.size(); ) {
        if (intervals[i][0] > newInterval[1]) {
            ans.push_back(newInterval);
            for (; i < intervals.size(); i++)
                ans.push_back(intervals[i]);
        } else if (intervals[i][1] < newInterval[0]) 
            ans.push_back(intervals[i++]);
        else {
            int left = min(intervals[i][0], newInterval[0]), right = max(newInterval[1], intervals[i][1]);
            while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
                right = max(right, intervals[i][1]);
                i++;
            }
            ans.push_back(vector<int>{left, right});
        }
    }
    if (intervals[intervals.size() - 1][1] < newInterval[0]) ans.push_back(newInterval);
    return ans;
}

int main() {
    vector<int> newInterval(2), interval(2);
    vector<vector<int>> intervals;
    cin >> newInterval[0] >> newInterval[1];
    while (cin >> interval[0] >> interval[1]) {
        intervals.push_back(interval);
    }
    #if 0
    for (auto &x : intervals) {
        for (auto &y : x) cout << y << ", ";
        cout << endl;
    }
    #endif
    auto ans = insert(intervals, newInterval);
    for (auto &x : ans) {
        for (auto &y : x) cout << y << " "; 
        cout << endl;
    }
    return 0;
}
