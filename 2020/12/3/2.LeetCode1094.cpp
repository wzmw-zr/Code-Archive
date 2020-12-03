/*************************************************************************
	> File Name: 2.LeetCode1094.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月03日 星期四 18时17分45秒
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

struct Traveler {
    int cnt;
    int start;
    int end;
    Traveler() = default;
    Traveler(vector<int> a) : cnt(a[0]), start(a[1]), end(a[2]) {};
    bool operator<(const struct Traveler &a) const {
        return this->start == a.start ? this->end < a.end : this->start < a.start;
    }
};

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> in(1005, 0), out(1005, 0);
    for (auto &x : trips) in[x[1]] += x[0], out[x[2]] += x[0];
    int cnt = 0;
    for (int i = 0; i <= 1000; i++) {
        cnt -= out[i];
        cnt += in[i];
        if (cnt > capacity) return false;
    }
    return true;
}

int main() {
    int capacity, x, y, z;
    vector<vector<int>> trips;
    cin >> capacity;
    while (cin >> x >> y >> z) trips.push_back({x, y, z});
    cout << (carPooling(trips, capacity) ? "Yes" : "No") << endl;
    return 0;
}
