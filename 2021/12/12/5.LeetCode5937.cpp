/*************************************************************************
	> File Name: 5.LeetCode5937.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月12日 星期日 22时49分58秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
    string name;
    int score;

    Node() = default;
    Node(string name, int score) : name(name), score(score) {}

    bool operator<(const struct Node &that) const {
        return this->score == that.score ? this->name < that.name : this->score > that.score;
    }

    bool operator==(const struct Node &that) const {
        return this->name == that.name && this->score == that.score;
    }
};

struct My_TreeNode {
    Node val;
    My_TreeNode *left;
    My_TreeNode *right;
    int height;
    int size;

    My_TreeNode() : val(Node("", 0)), left(this), right(this), height(0), size(0) {}
    My_TreeNode(Node val, My_TreeNode *left, My_TreeNode *right) : val(val), left(left), right(right), height(1), size(1) {}
};

My_TreeNode *LEAF = new My_TreeNode();

struct Tree {
    My_TreeNode *_root;

    Tree() : _root(LEAF) {}

    void update(My_TreeNode *root) {
        if (root == LEAF) return ;
        root->height = max(root->left->height, root->right->height) + 1;
        root->size = root->left->size + root->right->size + 1;
    }

    My_TreeNode *left_rotate(My_TreeNode *root) {
        My_TreeNode *right = root->right;
        root->right = right->left;
        right->left = root;
        update(root);
        update(right);
        return right;
    }

    My_TreeNode *right_rotate(My_TreeNode *root) {
        My_TreeNode *left = root->left;
        root->left = left->right;
        left->right = root;
        update(root);
        update(left);
        return left;
    }

    My_TreeNode *maintain(My_TreeNode *root) {
        if (root == LEAF) return root;
        if (abs(root->left->height- root->right->height) <= 1) return root;
        if (root->left->height > root->right->height) {
            if (root->left->left->height < root->left->right->height) root->left = left_rotate(root->left);
            root = right_rotate(root);
        } else {
            if (root->right->right->height < root->right->left->height) root->right = right_rotate(root->right);
            root = left_rotate(root);
        }
        return root;
    }

    My_TreeNode *insert(My_TreeNode *root, Node &val) {
        if (root == LEAF) {
            return new My_TreeNode(val, LEAF, LEAF);
        }
        if (root->val == val) return root;
        if (root->val < val) root->right = insert(root->right, val);
        else root->left = insert(root->left, val);
        update(root);
        root = maintain(root);
        return root;
    }

    string find_k_th_element(My_TreeNode *root, int k) {
        if (root == LEAF) return "";
        if (root->left->size + 1 == k) return (root->val).name;
        if (root->left->size + 1 < k) return find_k_th_element(root->right, k - root->left->size - 1);
        return find_k_th_element(root->left, k);
    }

    void insert(Node &val) {
        _root = insert(_root, val);
    }

    string find_k_th_element(int k) {
        return find_k_th_element(_root, k);
    }

    void level_print() {
        using PTI = pair<My_TreeNode *, int>;
        queue<PTI> que;
        que.push(PTI(_root, 1));
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            auto &&[root, level] = temp;
            if (root == LEAF) continue;
            cout << "level = "  << level << ", (" << (root->val).name << ", " << (root->val).score << ") " << "size = " << root->size << ", height = " << root->height << endl;
            if (root->left != LEAF) que.push(PTI(root->left, level + 1));
            if (root->right != LEAF) que.push(PTI(root->right, level + 1));
        }
    }

    void print(My_TreeNode *root, int level) {
        if (root == LEAF) return ;
        cout << "level = "  << level << ", (" << (root->val).name << ", " << (root->val).score << ") " << "size = " << root->size << ", height = " << root->height << endl;
        print(root->left, level + 1);
        print(root->right, level + 1);
    }

    void print() {
        print(_root, 1);
    }
};

class SORTracker {
public:
    Tree tree;
    int ind;
    SORTracker() : tree(Tree()), ind(1) {}

    void add(string name, int score) {
        Node val(name, score);
        tree.insert(val);
        tree.print();
        cout << endl;
        tree.level_print();
        cout << endl;
    }

    string get() {
        string ans = tree.find_k_th_element(ind);
        ind++;
        return ans;
    }
};

int main() {
    return 0;
}
