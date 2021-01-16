/*************************************************************************
	> File Name: 4.LeetCode351.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月16日 星期六 18时06分00秒
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

typedef pair<int, int> PII;

vector<vector<PII>> direction;

void init() {
    direction.push_back(vector<PII>({PII(1, 0)}));
    direction.push_back(vector<PII>({PII(-1, 0)}));
    direction.push_back(vector<PII>({PII(0, 1)}));
    direction.push_back(vector<PII>({PII(0, -1)}));
    direction.push_back(vector<PII>({PII(2, 0), PII(1, 0)}));
    direction.push_back(vector<PII>({PII(-2, 0), PII(-1, 0)}));
    direction.push_back(vector<PII>({PII(0, 2), PII(0, 1)}));
    direction.push_back(vector<PII>({PII(0, -2), PII(0, -1)}));
    direction.push_back(vector<PII>({PII(1, 1)}));
    direction.push_back(vector<PII>({PII(1, -1)}));
    direction.push_back(vector<PII>({PII(-1, 1)}));
    direction.push_back(vector<PII>({PII(-1, -1)}));
    direction.push_back(vector<PII>({PII(2, 2), PII(1, 1)}));
    direction.push_back(vector<PII>({PII(2, -2), PII(1, -1)}));
    direction.push_back(vector<PII>({PII(-2, 2), PII(-1, 1)}));
    direction.push_back(vector<PII>({PII(-2, -2), PII(-1, -1)}));

    direction.push_back(vector<PII>({PII(1, 2), PII(0, 1), PII(1, 1)}));
    direction.push_back(vector<PII>({PII(1, -2), PII(0, -1), PII(1, -1)}));
    direction.push_back(vector<PII>({PII(-1, 2), PII(0, 1), PII(-1, 1)}));
    direction.push_back(vector<PII>({PII(-1, -2), PII(0, -1), PII(-1, -1)}));
    direction.push_back(vector<PII>({PII(2, 1), PII(1, 0), PII(1, 1)}));
    direction.push_back(vector<PII>({PII(2, -1), PII(1, 0), PII(1, -1)}));
    direction.push_back(vector<PII>({PII(-2, 1), PII(-1, 0), PII(-1, 1)}));
    direction.push_back(vector<PII>({PII(-2, -1), PII(-1, 0), PII(-1, -1)}));
}

bool is_valid(vector<vector<bool>> &check, vector<PII> &item, int &x, int &y) {
    for (int i = 1; i < item.size(); i++) {
        if (check[x + item[i].first][y + item[i].second]) continue;
        return false;
    }
    return true;
}

int dfs(int x, int y, vector<vector<bool>> &check, int &m, int &n, int step) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || check[x][y] || step > n) return 0;
    int ans = 0;
    if (step >= m && step <= n) ans++;
    check[x][y] = true;;
    for (auto &item : direction) {
        auto [r, c] = item[0];
        int x_t = x + r;
        int y_t = y + c;
        if (x_t < 0 || x_t >= 3 || y_t < 0 || y_t >= 3 || check[x_t][y_t] || step == n) continue;
        if (!is_valid(check, item, x, y)) continue;
        ans += dfs(x_t, y_t, check, m, n, step + 1);
    }
    check[x][y] = false;
    return ans;
}

int numberOfPatterns(int m, int n) {
    init();
    int ans = 0;
    vector<vector<bool>> check(3, vector<bool>(3, false));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) ans += dfs(i, j, check, m, n, 1);
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << numberOfPatterns(m, n) << endl;
    return 0;
}
