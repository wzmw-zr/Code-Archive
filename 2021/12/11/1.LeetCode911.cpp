/*************************************************************************
	> File Name: 1.LeetCode911.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月11日 星期六 08时44分34秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
    int tickets;
    int last_time;
    int id;

    Node() = default;
    Node(int tickets, int last_time, int id) : tickets(tickets), last_time(last_time), id(id) {}

    bool operator<(const struct Node &that) const {
        return this->tickets == that.tickets ? this->last_time > that.last_time : this->tickets > that.tickets;
    }
};

class TopVotedCandidate {
public:
    vector<int> leaders;
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) : leaders(vector<int>(static_cast<int>(times.size()))), times(times) {
        unordered_map<int, vector<int>> mp;
        set<Node> st;
        int n = times.size();
        for (int i = 0; i < n; i++) {
            if (!mp.count(persons[i])) {
                mp[persons[i]] = vector<int>({1, times[i]});
                st.insert(Node(1, times[i], persons[i]));
            } else {
                st.erase(Node(mp[persons[i]][0], mp[persons[i]][1], persons[i]));
                mp[persons[i]][0]++;
                mp[persons[i]][1] = times[i];
                st.insert(Node(mp[persons[i]][0], mp[persons[i]][1], persons[i]));
            }
            leaders[i] = st.begin()->id;
        }
    }

    int q(int t) {
        int l = 0, r = static_cast<int>(times.size()) - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (times[mid] <= t) l = mid;
            else r = mid - 1;
        }
        return leaders[l];
    }
};

int main() {
    return 0;
}
