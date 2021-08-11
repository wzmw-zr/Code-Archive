/*************************************************************************
	> File Name: 5.LeetCode352.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月11日 星期三 17时11分54秒
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
    /** Initialize your data structure here. */
    set<PII> st{};

    SummaryRanges() {}

    void addNum(int val) {
        int left = val, right = val;
        for (auto iter = st.begin(); iter != st.end(); ) {
            if ((*iter).first > right + 1) break;
            if ((*iter).second < left - 1) {
                iter++;
                continue;
            }
            left = min(left, (*iter).first);
            right = max(right, (*iter).second);
            iter = st.erase(iter);
        }
        st.insert(move(PII(left, right)));
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto &&[l, r] : st) ans.push_back(move(vector<int>({l, r})));
        return ans;
    }
};

int main() {
    return 0;
}
