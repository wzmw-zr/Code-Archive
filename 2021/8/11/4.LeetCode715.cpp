/*************************************************************************
	> File Name: 4.LeetCode715.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月11日 星期三 13时51分10秒
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

class RangeModule {
public:
    set<PII> st{};
    RangeModule() {}

    void addRange(int left, int right) {
        for (auto iter = st.begin(); iter != st.end(); ) {
            if ((*iter).first > right || (*iter).second < left) iter++;
            else left = min(left, (*iter).first), right = max(right, (*iter).second), iter = st.erase(iter);
        }
        st.insert(PII(left, right));
    }

    bool queryRange(int left, int right) {
        for (auto p : st) {
            if (left >= p.first && right <= p.second) return true;
        }
        return false;
    }

    void removeRange(int left, int right) {
        set<PII> temp;
        for (auto &&[l, r] : st) {
            if (l >= right || r <= left) {
                temp.insert(move(PII(l, r)));
                continue;
            }
            if (l >= left && r <= right) continue;
            else if (l <= left && r <= right) {
                temp.insert(move(PII(l, left)));
            } else if (l >= left && r >= right) {
                temp.insert(move(PII(right, r)));
            } else {
                if (left > l) temp.insert(move(PII(l, left)));
                if (r > right) temp.insert(move(PII(right, r)));
            }
        }
        st = temp;
    }
};

int main() {
    return 0;
}
