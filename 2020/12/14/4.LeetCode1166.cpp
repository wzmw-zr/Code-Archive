/*************************************************************************
	> File Name: 4.LeetCode1166.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月14日 星期一 18时13分01秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int value;
    unordered_map<string, TreeNode *> mp;
    TreeNode() = default;
    TreeNode(int value) : value(value) {}
};

class FileSystem {
public:
    TreeNode *root;

    FileSystem() : root(new TreeNode()) {}

    int check(string &path) {
        int ind = 0;
        while (path[ind]) {
            int cnt = 0;
            while (path[ind] && path[ind] == '/') ind++, cnt++;
            if (cnt - 1) return 0;
            cnt = 0;
            while (path[ind] && path[ind] != '/') ind++, cnt++;
            if (!cnt) return 0;
        }
        return 1;
    }

    int check(vector<string> &path) {
        int n = path.size(), ind = 0;
        TreeNode *temp = root;
        while (ind < n && temp) {
            if (temp->mp.count(path[ind])) temp = temp->mp[path[ind++]];
            else break;
        }
        if (ind < n - 1 || ind == n) return 0;
        return 1;
    }

    vector<string> split(string &path) {
        vector<string> ans;
        int ind = 0;
        while (path[ind]) {
            string temp = "";
            while (path[ind] && path[ind] == '/') ind++;
            while (path[ind] && path[ind] != '/') temp += path[ind++];
            if (temp.size()) ans.push_back(temp);
        } 
        return ans;
    }

    void insert(vector<string> &path, int value) {
        int n = path.size(), ind = 0;
        TreeNode *temp = root;
        while (ind < n - 1) temp = temp->mp[path[ind++]];
        temp->mp[path[ind]] = new TreeNode(value);
    }

    bool createPath(string path, int value) {
        if (!check(path)) return false;
        vector<string> part = split(path);
        if (!check(part)) return false;
        insert(part, value);
        return true;
    }

    int get(string path) {
        if (!check(path)) return -1;
        vector<string> part = split(path);
        TreeNode *temp = root;
        int n = part.size(), ind = 0;
        while (ind < n && temp) {
            if (temp->mp.count(part[ind])) temp = temp->mp[part[ind++]];
            else return -1;
        }
        if (!temp) return -1;
        return temp->value;
    }
};

int main() {
    return 0;
}
