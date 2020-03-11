/*************************************************************************
	> File Name: 2.adjacent.table.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月10日 星期二 14时46分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Edge {
    int edge_value, next_vertix;
} Edge;

typedef struct Vertix {
    int node_value;
    vector<Edge> edge;
} Vertix;

typedef struct Graph {
    vector<Vertix> vertix; 
} Graph;

Graph *newGraph() {
    Graph *g = (Graph *) calloc(sizeof(Graph), 1);
    return g;
}

int main() {
    Graph *g = newGraph(); 
    int n, m, node_value, edge_value, next;
    cin >> n;
    (g->vertix).resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m >> node_value;
        (g->vertix)[i].node_value = node_value;
        (g->vertix)[i].edge.resize(m + 1);
        for (int j = 1; j <= m; j++) {
            cin >> edge_value >> next;
            ((g->vertix)[i].edge[j]).edge_value = edge_value;
            ((g->vertix)[i].edge[j]).next_vertix = next;
        }
    }
    return 0;
}
