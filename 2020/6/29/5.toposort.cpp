/*************************************************************************
	> File Name: 5.toposort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月29日 星期一 19时58分08秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

struct Node {
    vector<int> out_edge;
    int in_edge_cnt = 0;
};

struct Graph {
    vector<Node> node;
    Graph(int n) {
        node.resize(n);
    }

    void addEdge(int x, int y) {
        node[x].out_edge.push_back(y);
        node[y].in_edge_cnt++;
    }

    void toposort() {
        queue<int> que;
        vector<int> res;
        for (int i = 0; i < node.size(); i++) {
            if (node[i].in_edge_cnt == 0) 
                que.push(i);
        }
        while (!que.empty()) {
            int zero_ind = que.front();
            res.push_back(zero_ind);
            que.pop();
            for (int i = 0; i < node[zero_ind].out_edge.size(); i++) {
                if (--node[node[zero_ind].out_edge[i]].in_edge_cnt == 0)
                    que.push(node[zero_ind].out_edge[i]);
            }
        }
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 3);
    g.toposort();
    return 0;
}
