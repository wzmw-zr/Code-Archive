/*************************************************************************
	> File Name: 6.BTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月07日 星期日 21时35分38秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <tuple>
#include <ctime>
using namespace std;

const int M = 5;

struct Node {
    int cnt;
    int vals[2 * M + 1];
    Node *next[2 * M + 2];

    Node() : cnt(0) {
        memset(vals, 0, sizeof(vals));
        memset(next, 0, sizeof(next));
    }

    void insert(int ind, int val) {
        for (int i = cnt - 1; i >= ind; i--) vals[i + 1] = vals[i];
        for (int i = cnt; i >= ind; i--) next[i + 1] = next[i];
        vals[ind] = val;
        cnt++;
    }

    void clear() {
        cnt = 0;
        memset(vals, 0, sizeof(vals));
        memset(next, 0, sizeof(next));
    }
};

ostream &operator<<(ostream &out, Node *node) {
    out << "(";
    for (int i = 0; i < node->cnt; i++) {
        if (i) out << ",";
        out << node->vals[i];
    }
    out << ")";
    return out;
}

struct BTree {
    Node *_root;

    BTree() : _root(new Node()) {}

    void insert(int val) {
        _root = insert(_root, val);
        if (_root->cnt == (2 * M + 1)) {
            auto &&[left, right, mid] = split(_root);
            _root->clear();
            _root->cnt = 1;
            _root->vals[0] = mid;
            _root->next[0] = left;
            _root->next[1] = right;
        }
    }

    tuple<Node *, Node *, int> split(Node *root) {
        cout << "split" << endl;
        cout << "(";
        for (int i = 0; i < root->cnt; i++) cout << root->vals[i] << " ";
        cout << ")" << endl;
        int mid = root->vals[M];
        Node *left = new Node();
        Node *right = new Node();

        for (int i = 0; i < M; i++) left->vals[i] = root->vals[i];
        left->cnt = M;
        for (int i = 0; i <= M; i++) left->next[i] = root->next[i];

        for (int i = 0; i < M; i++) right->vals[i] = root->vals[i + 1 + M];
        right->cnt = M;
        for (int i = 0; i <= M; i++) right->next[i] = root->next[i + 1 + M];

        return {left, right, mid};
    }


    void insert_maintain(Node *root, int ind) {
        if (!root->next[ind]) return ;
        if (root->next[ind]->cnt == (2 * M + 1)) {
            auto &&[left, right, mid] = split(root->next[ind]);
            root->insert(ind, mid);
            delete root->next[ind];
            root->next[ind] = left;
            root->next[ind + 1] = right;
        }
    }

    int get_ind(Node *root, int val) {
        int l = 0, r = root->cnt;
        while (l < r) {
            int mid = (l + r) / 2;
            if (root->vals[mid] < val) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    Node *insert(Node *root, int val) {
        if (!root) return nullptr;
        int ind = get_ind(root, val);
        if (root->vals[ind] == val) return root;
        if (!root->next[ind]) root->insert(ind, val);
        else root->next[ind] = insert(root->next[ind], val);
        insert_maintain(root, ind);
        return root;
    }

    void print(Node *root) {
        if (!root) return ;
        for (int i = 0; i < root->cnt; i++) {
            print(root->next[i]);
            cout << root->vals[i] << " ";
        }
        print(root->next[root->cnt]);
    }

    void print() {
        print(_root);
    }

    void level_print() {
        using PNI = pair<Node *, int>;
        queue<PNI> que;
        que.push(PNI(_root, 0));
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            cout << temp.first << " " << temp.second << endl;
            for (int i = 0; i <= temp.first->cnt; i++) {
                if (!temp.first->next[i]) break;
                que.push(PNI(temp.first->next[i], temp.second + 1));
            }
        }
    }
};

int main() {
    BTree tree;
    int n;
    cin >> n;
    srand(time(0));
    for (int i = 1; i <= n; i++) tree.insert((rand() % 1000007) + 1);
    tree.level_print();
    tree.print();
    cout << endl;
    return 0;
}
