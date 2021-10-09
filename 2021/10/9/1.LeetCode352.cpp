/*************************************************************************
	> File Name: 1.LeetCode352.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月09日 星期六 08时23分27秒
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

using PII = pair<int, int>;

class SummaryRanges {
public:
    set<PII> intervals;

    SummaryRanges() {}

    void addNum(int val) {
        PII t = PII(val, val);
        for (auto iter = intervals.begin(); iter != intervals.end(); ) {
            if ((iter->first > t.second + 1) || (iter->second + 1 < t.first)) {
                iter++;
                continue;
            }
            t.first = min(t.first, iter->first);
            t.second = max(t.second, iter->second);
            iter = intervals.erase(iter);
        }
        intervals.insert(t);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto [l, r] : intervals) ans.push_back(vector<int>({l, r}));
        return ans;
    }
};

int main() {
    return 0;
}
