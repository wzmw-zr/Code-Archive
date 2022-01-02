/*************************************************************************
	> File Name: 1.LeetCode390.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月02日 星期日 09时39分27秒
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

int dfs(int n, int dir) {
    if (n == 1) return 1;
    int ind = dfs(n / 2, 1 - dir);
    if (dir == 0) return ind * 2;
    if (n & 1) return ind * 2;
    return ind * 2 - 1;
}

int lastRemaining(int n) {
    return dfs(n, 0);
}

int main() {
    int n;
    cin >> n;
    cout << lastRemaining(n) << endl;
    return 0;
}
