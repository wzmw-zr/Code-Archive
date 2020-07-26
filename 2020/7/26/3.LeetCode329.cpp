/*************************************************************************
	> File Name: 3.LeetCode329.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月26日 星期日 08时15分47秒
 ************************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;


int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int longestIncreasingPath(vector<vector<int>> &matrix, vector<vector<int>> &check, int x, int y, stack<int> &st, int &ans, vector<vector<int>> &mp) {
    int temp = ans;
    if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) {
        ans = max(temp, (int) st.size());
        return 0;
    }
    if (check[x][y]) {
        ans = max(temp, (int) st.size());
        return 0;
    }
    if (!st.size()) {
        st.push(matrix[x][y]);
        check[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            if (mp[x_t][y_t]) mp[x][y] = max(mp[x][y], mp[x_t][y_t] + 1);
            else mp[x][y] = max(mp[x][y], longestIncreasingPath(matrix, check, x_t, y_t, st, ans, mp) + 1);
        }
        st.pop();
        check[x][y] = 0;
    } else {
        if (matrix[x][y] <= st.top()) {
            ans = max(temp, (int) st.size());
            return 0;
        } else {
            st.push(matrix[x][y]);
            check[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int x_t = x + dir[i][0];
                int y_t = y + dir[i][1];
                if (mp[x_t][y_t]) mp[x][y] = max(mp[x][y], mp[x_t][y_t] + 1);
                else mp[x][y] = max(mp[x][y], longestIncreasingPath(matrix, check, x_t, y_t, st, ans, mp) + 1);
            }
            st.pop();
            check[x][y] = 0;
        }
    }
    return mp[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int len = matrix.size();
    if (len == 0) return 0;
    int width = matrix[0].size();
    int ans = 0;
    vector<vector<int>> check(len + 5, vector<int>(width + 5, 0));
    vector<vector<int>> mp(len + 5, vector<int>(width + 5, 0));
    stack<int> st;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++) {
            longestIncreasingPath(matrix, check, i, j, st, ans, mp);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}

