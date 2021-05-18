/*************************************************************************
	> File Name: 2.LeetCode1851.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月18日 星期二 23时02分06秒
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

struct Event {
    int pos;
    int type;
    int param;

    Event() = default;
    Event(int pos, int type, int param) : pos(pos), type(type), param(param) {};

    bool operator<(const Event &that) const {
        return this->pos < that.pos || ((this->pos == that.pos) && (this->type < that.type));
    }
};


vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    vector<Event> events;
    for (auto interval : intervals) {
        events.push_back(Event(interval[0], 0, interval[1]));
        events.push_back(Event(interval[1], 2, interval[0]));
    }
    int n = queries.size();
    for (int i = 0; i < n; i++) 
        events.push_back(Event(queries[i], 1, i));
    sort(events.begin(), events.end());
    multiset<int> st;
    vector<int> ans(n);
    for (auto &event : events) {
        if (event.type == 0) {
            st.insert(event.param - event.pos + 1);
        } else if (event.type == 1) {
            ans[event.param] = st.empty() ? -1 : *st.begin();
        } else {
            auto iter = st.find(event.pos - event.param + 1);
            st.erase(iter);
        }
    }
    return ans;
}

int main() {
    return 0;
}
