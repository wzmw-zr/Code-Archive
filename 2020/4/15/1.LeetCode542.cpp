/*************************************************************************
	> File Name: 1.LeetCode542.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月15日 星期三 18时37分51秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<ctime>
#include<unistd.h>
using namespace std;

typedef struct Node {
    int x, y, step;
} Node;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> ret, check;
    queue<Node> que;
    int x_max_len = 0, y_max_len = 0;
    if (matrix.size()) {
        x_max_len = matrix.size();
        if (matrix[0].size()) y_max_len = matrix[0].size();
    }
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> tmp, ret_tmp;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j]) tmp.push_back(0);
            else {
                tmp.push_back(-1);
                que.push({i, j, 0});
            }
            ret_tmp.push_back(0);
        }
        ret.push_back(ret_tmp);
        check.push_back(tmp);
    }
    
    while (!que.empty()) {
        Node node = que.front();
        que.pop();
        ret[node.x][node.y] = node.step;
        for (int i = 0; i < 4; i++) {
            int x = node.x + dir[i][0];
            int y = node.y + dir[i][1];
            if (x < 0 || y < 0 || x >= x_max_len || y >= y_max_len) continue;
            if (check[x][y]) continue;
            que.push({x, y, node.step + 1});
            check[x][y] = 1;
        }
    }

    return ret;
}

int main() {
    vector<vector<int>> matrix, ret;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        int num;
        for(int j = 0; j < m; j++) {
            cin >> num;
            tmp.push_back(num);
        }
        matrix.push_back(tmp);
    }
    ret = updateMatrix(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            j && cout << " ";
            cout << ret[i][j];
        }
        cout << endl;
    }
    return 0;
}
