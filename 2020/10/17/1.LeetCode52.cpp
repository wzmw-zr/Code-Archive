/*************************************************************************
	> File Name: 1.LeetCode52.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月17日 星期六 07时57分45秒
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

struct Point {
    int x, y;

    Point() = default;
    Point(int x, int y) : x(x), y(y) {}

    bool can_eat(Point &b) {
        return this->x == b.x || this->y == b.y || abs(this->x - b.x) == abs(this->y - b.y);
    }
};

void dfs(vector<Point> &node, int row, int n, int &cnt) {
    if (row > n) {
        cnt++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        Point temp(row, i);
        for (int j = 0; j < node.size(); j++) {
            if (temp.can_eat(node[j])) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        node.push_back(temp);
        dfs(node, row + 1, n, cnt);
        node.pop_back();
    }
}

int totalNQueens(int n) {
    vector<Point> node;
    int cnt = 0;
    dfs(node, 1, n, cnt);
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << totalNQueens(n) << endl;
    return 0;
}
