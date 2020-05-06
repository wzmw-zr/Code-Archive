/*************************************************************************
	> File Name: 7.HZOJ241.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 19时12分27秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 100000

struct Node {
    long x, y, type;
};

int n;
Node node[2 * MAX_N + 5];

int cmp(Node a, Node b) {
    return a.x < b.x;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
        node[i].type = 1;
    }
    for (int i = n; i < 2 * n; i++) {
        cin >> node[i].x >> node[i].y; 
        node[i].type = 0;
    }
    sort(node, node + 2 * n, cmp);
    return 0;
}
