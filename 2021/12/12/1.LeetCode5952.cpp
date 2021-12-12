/*************************************************************************
	> File Name: 1.LeetCode5952.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月12日 星期日 21时40分59秒
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

int countPoints(string rings) {
    vector<unordered_set<char>> rods(10, unordered_set<char>());
    for (int i = 0; rings[i]; i += 2) rods[rings[i + 1] - '0'].insert(rings[i]);
    int cnt = 0;
    for (int i = 0; i <= 9; i++) cnt += rods[i].size() == 3 ? 1 : 0;
    return cnt;
}

int main() {
    return 0;
}
