/*************************************************************************
	> File Name: 1.LeetCode789.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月22日 星期日 17时04分30秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    for (auto x : ghosts) {
        if ((abs(target[0] - x[0]) + abs(target[1] - x[1])) <= (abs(target[0]) + abs(target[1]))) return false;
    }
    return true;
}

int main() {
    vector<int> target(2);
    vector<vector<int>> ghosts;
    cin >> target[0] >> target[1];
    int x, y;
    while (cin >> x >> y) ghosts.push_back({x, y});
    cout << (escapeGhosts(ghosts, target) ? "True" : "False") << endl;
    return 0;
}
