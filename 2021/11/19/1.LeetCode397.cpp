/*************************************************************************
	> File Name: 1.LeetCode397.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月19日 星期五 08时21分20秒
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

int dfs(long n, unordered_map<long, int> &mp) {
    if (n == 1) return 0;
    if (mp.count(n)) return mp[n];
    if (n & 1) {
        int x = dfs(n + 1, mp);
        int y = dfs(n - 1, mp);
        mp[n] = min(x, y) + 1;
    } else mp[n] = dfs(n / 2, mp) + 1;
    return mp[n];
}

int integerReplacement(int n) {
    unordered_map<long, int> mp;
    return dfs((long) n, mp);
}

int main() {
    int n;
    cin >> n;
    cout << integerReplacement(n) << endl;
    return 0;
}
