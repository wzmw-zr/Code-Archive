/*************************************************************************
	> File Name: 4.LeetCode252.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月18日 星期四 22时48分16秒
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

bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= intervals[i - 1][1]) continue;
        return false;
    }
    return true;
}

int main() {
    return 0;
}
