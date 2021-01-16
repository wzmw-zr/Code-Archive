/*************************************************************************
	> File Name: 2.LeetCode1583.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月17日 星期日 00时33分31秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

void check(int x, int y, int u, int v, vector<vector<int>> &relation, vector<int> &unhappy) {
    if (relation[x][u] > relation[x][y] && relation[u][x] > relation[u][v]) unhappy[x] = 1;
}

int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    vector<vector<int>> relation(n, vector<int>(n, 0));
    vector<int> unhappy(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = n - 2, i = 1; j >= 0; j--, i++) relation[i][preferences[i][j]] = i;
    }
    int m = pairs.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int x = pairs[i][0];
            int y = pairs[i][1];
            int u = pairs[j][0];
            int v = pairs[j][1];
            check(x, y, u, v, relation, unhappy);
            check(x, y, v, u, relation, unhappy);
            check(y, x, u, v, relation, unhappy);
            check(y, x, v, u, relation, unhappy);
            check(u, v, x, y, relation, unhappy);
            check(u, v, y, x, relation, unhappy);
            check(v, u, x, y, relation, unhappy);
            check(v, u, y, x, relation, unhappy);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += unhappy[i];
    return ans;
}

int main() {
    return 0;
}
