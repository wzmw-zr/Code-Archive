/*************************************************************************
	> File Name: 3.LeetCode911.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月13日 星期六 20时26分01秒
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

class TopVotedCandidate {
public:
    unordered_map<int, int> mp;
    vector<int> leader;
    vector<int> ticket;
    vector<int> times;
    int people;
    int max_ticket;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) : 
    people(0), max_ticket(0), ticket((int) persons.size() + 1, 0), 
    leader((int) persons.size() + 1, 0), times(times) {
        int n = persons.size();
        for (int i = 0; i < n; i++) {
            ticket[persons[i]]++;
            if (ticket[persons[i]] >= max_ticket) {
                people = persons[i];
                max_ticket = ticket[persons[i]];
            }
            leader[i] = people;
        }
    }

    int binary_search(vector<int> &times, int t) {
        int l = 0, r = times.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (times[mid] == t) return mid;
            else if (times[mid] < t) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    int q(int t) {
        int ind = binary_search(times, t);
        return leader[ind];
    }
};


int main() {
    return 0;
}
