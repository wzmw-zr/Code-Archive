/*************************************************************************
	> File Name: 1.LeetCode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月19日 星期六 15时22分15秒
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

int row_check[10];
int coloum_check[10];

void dfs(int n, vector<vector<int>> matrix, set<vector<vector<int>>> &st, int cnt, int k) {
    if (cnt == k) {
        st.insert(matrix);
        return ;
    }
    if (cnt > k) return ;
    for (int i = 0; i < n; i++) {
        if (row_check[i]) continue;
        auto temp = matrix;
        int num = cnt;
        row_check[i] = 1;
        for (int j = 0; j < n; j++) {
            if (temp[i][j]) continue;
            temp[i][j] = 1;
            num++;
        }
        dfs(n, temp, st, num, k);
        row_check[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (coloum_check[i]) continue;
        auto temp = matrix;
        int num = cnt;
        coloum_check[i] = 1;
        for (int j = 0; j < n; j++) {
            if (temp[j][i]) continue;
            temp[j][i] = 1;
            num++;
        }
        dfs(n, temp, st, num, k);
        coloum_check[i] = 0;
    }
}

int paintingPlan(int n, int k) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    set<vector<vector<int>>> st;
    dfs(n, matrix, st, 0, k);
    return st.size();
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << paintingPlan(n, k) << endl;
    return 0;
}
