/*************************************************************************
	> File Name: 2.LeetCode281.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月12日 星期六 00时18分40秒
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

class ZigzagIterator {
public:
    vector<int> v1_;
    vector<int> v2_;
    int ind_1;
    int ind_2;
    int turn;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : v1_(move(v1)), v2_(move(v2)), ind_1(0), ind_2(0), turn(0) {}

    int next() {
        int res;
        if (ind_1 < v1_.size() && ind_2 < v2_.size()) {
            if (turn == 0) {
                res = v1_[ind_1++];
                turn = 1;
            } else {
                res = v2_[ind_2++];
                turn = 0;
            }
        } else {
            res = ind_1 < v1_.size() ? v1_[ind_1++] : v2_[ind_2++];
        }
        return res;
    }

    bool hasNext() {
        return ind_1 < v1_.size() || ind_2 < v2_.size();
    }
};

int main() {
    return 0;
}
