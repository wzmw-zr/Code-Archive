/*************************************************************************
	> File Name: 4.LeetCode5877.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月19日 星期日 10时41分20秒
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

class DetectSquares {
public:
    vector<unordered_map<int, int>> rows;
    vector<unordered_map<int, int>> cols;

    DetectSquares() : rows(vector<unordered_map<int, int>>(1001, unordered_map<int, int>())), cols(vector<unordered_map<int, int>>(1001, unordered_map<int, int>())) {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        rows[y][x]++;
        cols[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        for (auto &&[ind, cnt] : rows[y]) {
            if (x == ind) continue;
            int l = abs(ind - x);
            printf("x = %d, y = %d, l = %d\n", x, y, l);
            if (y + l <= 1000) {
                if (rows[y + l].count(ind) && rows[y + l].count(x)) 
                    ans += rows[y][ind] * rows[y + l][ind] * rows[y + l][x];
            }
            if (y - l >= 0) {
                if (rows[y - l].count(ind) && rows[y - l].count(x)) 
                    ans += rows[y][ind] * rows[y - l][ind] * rows[y - l][x];
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
