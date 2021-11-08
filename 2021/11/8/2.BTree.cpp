/*************************************************************************
	> File Name: 2.BTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月08日 星期一 10时42分36秒
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
using namespace std;

const int M = 2;

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

    void erase(int ind) {
        for (int i = ind; i < cnt - 1; i++) vals[i] = vals[i + 1];
        for (int i = ind; i < cnt; i++) next[i] = next[i + 1];
        vals[cnt - 1] = 0;
        next[cnt] = nullptr;
        cnt--;
    }

    void clear() {
        cnt = 0;
        memset(vals, 0, sizeof(vals));
        memset(next, 0, sizeof(next));
    }
};

ostream &operator<<(ostream &out, Node *node) {
    out << "(";
    for (int i = 0; i < node->cnt; i++) out << node->vals[i] << " ";
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
            _root->vals[0] = mid;
            _root->next[0] = left;
            _root->next[1] = right;
            _root->cnt++;
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

    tuple<Node *, Node *, int> split(Node *root) {
        int mid = root->vals[M];
        Node *left = new Node();
        Node *right = new Node();
        for (int i = 0; i < M; i++) left->vals[i] = root->vals[i];
        for (int i = 0; i <= M; i++) left->next[i] = root->next[i];
        for (int i = 0; i < M; i++) right->vals[i] = root->vals[i + M + 1];
        for (int i = 0; i <= M; i++) right->next[i] = root->next[i + M + 1];
        left->cnt = right->cnt = M;
        return {left, right, mid};
    }

    Node *merge(int mid, Node *left, Node *right) {
        Node *temp = new Node();
        for (int i = 0; i < left->cnt; i++) temp->vals[i] = left->vals[i];
        temp->vals[left->cnt] = mid;
        for (int i = 0; i < right->cnt; i++) temp->vals[i + left->cnt + 1] = right->vals[i];
        for (int i = 0; i <= left->cnt; i++) temp->next[i] = left->next[i];
        for (int i = 0; i <= right->cnt; i++) temp->next[i + left->cnt + 1] = right->next[i];
        temp->cnt = left->cnt + right->cnt + 1;
        return temp;
    }

    Node *maintain(Node *root, int ind) {
        if (!root || !root->next[ind]) return root;
        // if (!root || !root->next[ind]) return root;
        if (root->next[ind]->cnt == (2 * M + 1)) {
            auto &&[left, right, mid] = split(root->next[ind]);
            delete root->next[ind];
            root->insert(ind, mid);
            root->next[ind] = left;
            root->next[ind + 1] = right;
            return root;
        }
        if (root->next[ind]->cnt == (M - 1)) {
            if (ind < (2 * M)) {
                if (root->next[ind + 1]->cnt > M) {
                    root->next[ind]->insert(M - 1, root->vals[ind]);
                    root->next[ind]->next[M] = root->next[ind + 1]->next[0];
                    root->vals[ind] = root->next[ind + 1]->vals[0];
                    root->next[ind + 1]->erase(0);
                } else {
                    Node *temp = merge(root->vals[ind], root->next[ind], root->next[ind + 1]);
                    delete root->next[ind];
                    delete root->next[ind + 1];
                    root->erase(ind);
                    root->next[ind] = temp;
                }
            } else {
                if (root->next[ind - 1]->cnt > M) {
                    int t = root->next[ind - 1]->cnt;
                    root->next[ind]->insert(0, root->vals[ind - 1]);
                    root->next[ind]->next[0] = root->next[ind - 1]->next[t];
                    root->vals[ind - 1] = root->next[ind - 1]->vals[t - 1];
                    root->next[ind - 1]->erase(t - 1);
                } else {
                    Node *temp = merge(root->vals[ind - 1], root->next[ind - 1], root->next[ind]);
                    delete root->next[ind - 1];
                    delete root->next[ind];
                    root->erase(ind - 1);
                    root->next[ind - 1] = temp;
                }
            }
        }
        return root;
    }

    Node *insert(Node *root, int val) {
        if (!root) return nullptr;
        int ind = get_ind(root, val);
        cout << "ind = " << ind << endl;
        if (root->vals[ind] == val) return root;
        if (!root->next[ind]) root->insert(ind, val);
        else root->next[ind] = insert(root->next[ind], val);
        root = maintain(root, ind);
        return root;
    }

    void erase(int val) {
        _root = erase(_root, val);
    }

    int predecessor(Node *root, int ind) {
        Node *temp = root->next[ind];
        while (temp->next[temp->cnt]) temp = temp->next[temp->cnt];
        return temp->vals[temp->cnt - 1];
    }

    Node *erase(Node *root, int val) {
        if (!root) return nullptr;
        int ind = get_ind(root, val);
        if (root->vals[ind] == val) {
            if (!root->next[ind]) root->erase(ind);
            else {
                int pre = predecessor(root, ind);
                root->vals[ind] = pre;
                root->next[ind] = erase(root->next[ind], pre);
            }
        } else root->next[ind] = erase(root->next[ind], val);
        root = maintain(root, ind);
        return root;
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
    BTree btree;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
        btree.insert(i);
        btree.level_print();
        cout << endl;
    }
    btree.level_print();
    return 0;
}
