/*************************************************************************
	> File Name: 3.1012.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月27日 星期日 10时50分47秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

#define MAX_N 100000010

struct Node {
    int x, y;

    Node() = default;
    Node(int x, int y) : x(x), y(y) {}
};

unordered_map<int, Node> mp_i;
map<Node, int> mp_n;
queue<Node> que;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void init() {
    int ind = 0;
    Node node = Node(0, 0);
    mp_i[ind] = node;
    mp_n.insert(pair<Node, int>(node, ind++));
    que.push(node);
    while (ind < MAX_N)  {
        node = que.front();
        for (int i = 0; i < 4; i++) {
            Node temp = Node(node.x + dir[i][0], node.y + dir[i][1]);
            if (mp_n.find(temp) != mp_n.end()) continue;
            mp_i[ind] = temp;
            mp_n.insert(pair<Node, int>(temp, ind++));
        }
    }
}

int main() {
    init();
    return 0;
}
