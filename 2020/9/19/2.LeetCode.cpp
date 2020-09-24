/*************************************************************************
	> File Name: 2.LeetCode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月19日 星期六 15时52分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#if 0
int get_num(int n, int m) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    for (int i = 1; i <= m; i++) ans /= i;
    for (int i = 1; i <= n - m; i++) ans /= i;
    return ans;
}
#endif

int row_check[10];
int coloum_check[10];

int get_num(int cnt, int n, int m, set<vector<vector<int>> &st) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    dfs(cnt, n, m, matrix, st);
}

int paintingPlan(int n, int k) {
    int ans = 0;
    set<vector<vector<int>> st;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if ((i * n + j * n - i * j) == k) {
                vector<vector<int>> matrix(n, vector<int>(n, 0));
                dfs(n, i, j, matrix, st);
            }
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << paintingPlan(n, k) << endl;
    return 0;
}
