/*************************************************************************
	> File Name: 1.LeetCode2013.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月26日 星期三 08时54分12秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

class DetectSquares {
public:
    vector<vector<int>> cnts_;

    DetectSquares() : cnts_(vector<vector<int>>(1010, vector<int>(1010, 0))) {}

    void add(vector<int> point) {
        cnts_[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        // left down corner
        for (int i = 1; i <= min(x, y); i++) {
            ans += cnts_[x - i][y] * cnts_[x][y - i] * cnts_[x - i][y - i];
        }
        // left up corner
        for (int i = 1; i <= min(x, 1000 - y); i++) {
            ans += cnts_[x - i][y] * cnts_[x][y + i] * cnts_[x - i][y + i];
        }
        // right down corner
        for (int i = 1; i <= min(1000 - x, y); i++) {
            ans += cnts_[x + i][y] * cnts_[x][y - i] * cnts_[x + i][y - i];
        }
        // right up corner
        for (int i = 1; i <= min(1000 - x, 1000 - y); i++) {
            ans += cnts_[x + i][y] * cnts_[x][y + i] * cnts_[x + i][y + i];
        }
        return ans;
    }
};

int main() {
    return 0;
}
