/*************************************************************************
	> File Name: BTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月30日 星期四 21时26分40秒
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
#include <tuple>
using namespace std;

// Just a Draft
static int m = 50;

struct TreeNode {
    int cnt;
    vector<int> nums;
    vector<TreeNode *> children;

    TreeNode() : cnt(0), nums(vector<int>(2 * m + 1, 0)), children(vector<TreeNode *>(2 * m + 2, nullptr)) {}

    int get_index(int x) {
        int l = -1, r = cnt - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] < x) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    void insert(int ind, int x) {
        // move nums and pointers, only in leaf.
        for (int i = cnt - 1; i >= ind; i--) nums[i + 1] = nums[i];
        for (int i = cnt; i >= ind; i--) children[i + 1] = children[i];
        nums[ind] = x;
        cnt++;
    }

    void erase(int ind) {
        // move nums and pointers, only in leaf.
        for (int i = ind + 1; i < cnt; i++) nums[i - 1] = nums[i];
        for (int i = ind + 1; i < cnt + 1; i++) children[i - 1] = children[i];
        nums[cnt] = 0;
        children[cnt + 1] = nullptr;
        cnt--;
    }
};

struct BTree {
    TreeNode *_root;

    BTree() : _root(new TreeNode()) {}

    bool _search(TreeNode *root, int x) {
        if (!root) return false;
        // get the last index of element less than x in root
        int ind = root->get_index(x);
        // if all elements  less than x, or no element in the node
        if (ind == root->cnt - 1) return _search(root->children[ind + 1], x);
        if (root->nums[ind + 1] == x) return true;
        return _search(root->children[ind + 1], x);
    }

    bool search(int x) {
        return _search(_root, x);
    }

    tuple<TreeNode *, TreeNode *> split(TreeNode *root) {
        if (!root) return tuple<TreeNode *, TreeNode *>(nullptr, nullptr);
        TreeNode *left = new TreeNode();
        TreeNode *right = new TreeNode();
        for (int i = 0; i < m; i++) left->nums[i] = root->nums[i];
        for (int i = 0; i <= m; i++) left->children[i] = root->children[i];
        for (int i = 0, j = m + 1; i < m; i++, j++) right->nums[i] = root->nums[j];
        for (int i = 0, j = m + 1; i <= m; i++, j++) right->children[i] = root->children[j];
        delete root;
        return tuple<TreeNode *, TreeNode *>(left, right);
    }

    TreeNode *maintain(TreeNode *root, int ind) {
        if (!root) return root;
        if (root->children[ind]->cnt >= m && root->children[ind]->cnt <= 2 * m) return root;
        if (root->children[ind]->cnt == 2 * m + 1) {
            root->insert(ind, root->children[ind]->nums[m]);
            auto &&[left, right] = split(root->children[ind]);
            root->children[ind] = left;
            root->children[ind + 1] = right;
            return root;
        }
        if (root->children[ind]->cnt == m - 1) {
            if (ind == 0) {

            } else {

            }
        }
        return root;
    }

    TreeNode *_insert(TreeNode *root, int x) {
        if (!root) return nullptr;
        int ind = root->get_index(x);
        if (ind == root->cnt - 1) {
            if (root->cnt) {
                // if all the elements in the root less than x.
                if (root->children[ind + 1]) {
                    // if root has subtree ind + 1
                    root->children[ind + 1] = _insert(root->children[ind + 1], x);
                    root = maintain(root, ind + 1);
                } else {
                    root->insert(ind + 1, x);
                }
            } else {
                // the count of number in root to be 0, only happen in the top-level root.
                root->insert(ind + 1, x);
            }
            return root;
        }
        if (root->nums[ind + 1] == x) return root;
        if (!root->children[ind + 1]) {
            root->insert(ind + 1, x);
            return root;
        }
        root->children[ind + 1] = _insert(root->children[ind + 1], x);
        root = maintain(root, ind + 1);
        return root;
    }

    void insert(int x) {
        _root = _insert(_root, x);
    }

    # if 0
    TreeNode *_erase(TreeNode *root, int x) {
        if (!root) return root;
        int ind = root->get_index(x);
        if (ind == root->cnt - 1) {
            root = _erase(root->children[ind + 1], x);
            root = maintain(root, ind + 1);
            return root;
        }
        if (root->nums[ind + 1] == x) { 
            if (!root->children[0] && !root->children[root->cnt]) {
                root->erase(ind + 1);
            } else if (root->children[0]) {
                TreeNode *temp = predecessor(root);
                int t = temp->nums[temp->cnt - 1];
                root->nums[ind + 1] = t;
                root = _erase(root->children[0], t);
            } else {
                TreeNode *temp = successor(root);
                int t = temp->nums[0];
                root->nums[ind + 1] = t;
                root = _erase(root->children[root->cnt], t);
            }
        } else {
            root = _erase(root->children[ind + 1], x);
        }
        root = maintain(root, ind + 1);
    }

    void erase(int x) {
        _root = _erase(_root, x);
    }
    #endif
};

int main() {
    return 0;
}
