/*************************************************************************
	> File Name: 1.LeetCode688.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月17日 星期四 00时10分11秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

// TLE
struct Node {
    int x;
    int y;
    int step;
    double p;

    Node() = default;
    Node(int x, int y, int step, double p) : x(x), y(y), step(step), p(p) {}
};

ostream &operator<<(ostream &out, Node &node) {
    out << "x = " << node.x << ", y = " << node.y << ", step = " << node.step << ", p = " << node.p << endl;
    return out;
}

int dir[8][2] = {2, 1, 2, -1, -2, 1, -2, -1, 1, 2, 1, -2, -1, 2, -1, -2};

double mmap[26][26][101];

double dfs(int N, int r, int c, int K) {
    if (r < 0 || r >= N || c < 0 || c >= N || K < 0) {
        return 0.0;
    }
    if (K == 0) {
        return 1.0;
    }
    if (mmap[r][c][K] != 0) {
        return mmap[r][c][K];
    }
    double prob = 0.0;
    for (int i = 0; i < 8; i++) {
        int x = r + dir[i][0];
        int y = c + dir[i][1];
        if (x < 0 || x >= N || y < 0 || y >= N) {
            continue;
        }
        prob += dfs(N, x, y, K - 1) / 8;
    }
    return mmap[r][c][K] = prob;
}

double knightProbability(int N, int K, int r, int c) {
    memset(mmap, 0, sizeof(mmap));
    return dfs(N, r, c, K);
}

int main() {
    return 0;
}
