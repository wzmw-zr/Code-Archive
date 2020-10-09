/*************************************************************************
	> File Name: 4.CSP_1.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月09日 星期五 15时22分46秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 200

struct Node {
    int x, y, dis, num;

    int operator-(Node &b) {
        return pow(this->x - b.x, 2) + pow(this->y - b.y, 2);
    }
};

int n;
Node node;
Node point[MAX_N + 5];

bool cmp(Node &a, Node &b) {
    return a.dis == b.dis ? a.num < b.num : a.dis < b.dis;
}

int main() {
    cin >> n >> node.x >> node.y;
    for (int i = 0; i < n; i++) cin >> point[i].x >> point[i].y;
    for (int i = 0; i < n; i++) point[i].dis = point[i] - node, point[i].num = i + 1;
    //sort(point, point + n, [](Node &a, Node &b){ return a.dis < b.dis; });
    sort(point, point + n, cmp);
    cout << point[0].num << endl;
    cout << point[1].num << endl;
    cout << point[2].num << endl;
    return 0;
}
