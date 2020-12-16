/*************************************************************************
	> File Name: 3.LeetCode1396.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月16日 星期三 10时15分49秒
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

typedef pair<string, int> PSI;
class UndergroundSystem {
public:
    unordered_map<string, vector<double>> station;
    unordered_map<int, PSI> passenger;

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        passenger[id] = PSI(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        station[passenger[id].first + " " + stationName].push_back(t - passenger[id].second);
        passenger.erase(passenger.find(id));
    }

    double getAverageTime(string startStation, string endStation) {
        double ans = 0;
        for (double x : station[startStation + " " + endStation]) ans += x;
        int n = station[startStation + " " + endStation].size();
        return ans / n;
    }
};

int main() {
    return 0;
}
