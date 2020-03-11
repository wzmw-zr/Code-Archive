/*************************************************************************
	> File Name: 1.adjacent.table.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月10日 星期二 10时07分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Edge {
    int metrics, next;
} Edge;

typedef struct Node {
    int value;
    vector<Edge> out_edge;
} Node;

vector<Node> graph;

int main() {

    return 0;
}
