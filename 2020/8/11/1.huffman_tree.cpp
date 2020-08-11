/*************************************************************************
	> File Name: 1.huffman_tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月11日 星期二 10时18分47秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct Node {
    char ch;
    string code;
    double frequency;
    Node *left, *right;

    Node() : code(""), frequency(0.0), left(nullptr), right(nullptr) {}
    Node(double frequency) : code(""), frequency(frequency), left(nullptr), right(nullptr) {}
    Node(char ch, double frequency) : ch(ch), code(""), frequency(frequency), left(nullptr), right(nullptr) {}

    bool operator<(Node &a) {
        return this->frequency > a.frequency;
    }
};

struct HuffmanTree {
    Node *root;
    int number;
    Node *arr;

    HuffmanTree() : root(nullptr), number(0), arr(nullptr) {}
    HuffmanTree(int n) : root(nullptr), number(n), arr(new Node[n]) {}

    void build(Node *arr);
};

void HuffmanTree::build(Node *arr) {
    #if 0
    for (auto x : arr) que.push(x);
    while (que.size() > 1) {
        Node node_1 = que.top();
        que.pop();
        Node node_2 = que.top();
        que.pop();
        Node temp;
    }
    #endif
}

int main() {
    int n;
    cin >> n;
    HuffmanTree tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree.arr[i].ch >> tree.arr[i].frequency;
    }
    tree.build(tree.arr);
    return 0;
}
