/*************************************************************************
	> File Name: 5.HZOJ400.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 19时22分10秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node {
    int x, y, step;
} Node;

int mmap[505][505];
int x1, y1, x2, y2;
int dir[12][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1, 2, 2, 2, -2, -2, 2, -2, -2};

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    queue<Node> que;
    que.push({x1, y1, 0});

    return 0;
}
