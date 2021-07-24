/*************************************************************************
	> File Name: 4.LeetCode5806.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月24日 星期六 23时16分54秒
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

// WA
#define LEFT 0
#define RIGHT 1

struct Point {
    int coord;
    int type;
    long long val;

    Point() = default;
    Point(int coord, int type, long long val) : coord(coord), type(type), val(val) {}

    bool operator<(const struct Point &that) const {
        return this->coord == that.coord ? this->type < that.type : this->coord < that.coord;
    }
};

vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    vector<Point> points;
    for (auto seg : segments) {
        points.push_back(Point{seg[0], LEFT, static_cast<long long>(seg[2])});
        points.push_back(Point{seg[1], RIGHT, static_cast<long long>(seg[2])});
    }
    sort(points.begin(), points.end());
    multiset<long long> pre;
    multiset<long long> st;
    int n = points.size();
    int left = points[0].coord;
    vector<vector<long long>> ans;
    for (int i = 0; i < n; ) {
        if (points[i].type == LEFT) {
            int ind = points[i].coord;
            while ((i < n) && (points[i].coord == ind)) {
                st.insert(points[i].val);
                i++;
            }
            if (!pre.empty()) {
                long long sum = 0;
                for (auto x : pre) sum += x;
                ans.push_back({left, ind, sum});
            }
            left = ind;
            pre = st;
        } else {
            int ind = points[i].coord;
            while ((i < n) && (points[i].coord == ind)) {
                if (points[i].type == RIGHT) st.erase(st.find(points[i].val));
                else st.insert(points[i].val);
                i++;
            }
            if (st != pre) {
                long long sum = 0;
                for (auto x : pre) sum += x;
                ans.push_back({left, ind, sum});
                left = ind;
                pre = st;
            } else {
                if (i < n) continue;
                long long sum = 0;
                for (auto x : pre) sum += x;
                ans.push_back({left, ind, sum});
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
