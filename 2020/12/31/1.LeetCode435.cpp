/*************************************************************************
	> File Name: 2.LeetCode435.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月31日 星期四 00时02分35秒
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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (!intervals.size()) return 0;
    int ans = 1;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ return a[1] < b[1]; });
    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (right <= intervals[i][0]) {
            ans++;
            right = intervals[i][1];
        } 
    }
    return intervals.size() - ans;
}

int main() {
    return 0;
}
