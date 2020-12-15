/*************************************************************************
	> File Name: 4.LeetCode588.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月15日 星期二 18时32分24秒
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

class FileSystem {
public:
    struct Node {
        string name;
        int type;

        Node() = default;
        Node(string name, int type) : name(name), type(type) {}
        virtual ~Node() = default;
    };

    struct File : public Node {
        string content;

        File() { 
            this->type = 0; 
            content = "";
        }
        File(string name) {
            this->name = name;
            this->type = 0;
            content = "";
        }
        ~File() override {}
    };

    struct Directory : public Node {
        string name;
        unordered_map<string, Node *> mp;

        Directory() { 
            this->type = 1; 
        }
        Directory(string name) {
            this->name = name;
            this->type = 1;
        }
        ~Directory() override {}
    };

    Node *__root;

    FileSystem() {
        __root = (Node *) new Directory("/");
    }

    vector<string> split(string &path) {
        vector<string> ans;
        int n = path.size(), ind = 0;
        while (ind < n) {
            string temp = "";
            while (ind < n && path[ind] == '/') ind++;
            while (ind < n && path[ind] != '/') temp += path[ind++];
            if (temp.size()) ans.push_back(temp);
        }
        return ans;
    }

    vector<string> ls(string path) {
        vector<string> part = split(path);
        Node *root = __root;
        for (string &s : part) root = ((Directory *) root)->mp[s];
        vector<string> ans;
        if (!root->type) {
            ans.push_back(root->name);
            return ans;
        }
        for (auto &&[name, ptr] : ((Directory *) root)->mp) ans.push_back(name);
        sort(ans.begin(), ans.end());
        return ans;
    }

    void mkdir(string path) {
        vector<string> part = split(path);
        Node *root = __root;
        for (string &s : part) {
            if (!((Directory *) root)->mp.count(s)) ((Directory *) root)->mp[s] = new Directory(s);
            root = ((Directory *) root)->mp[s];
        } 
    }

    void addContentToFile(string filePath, string content) {
        vector<string> path = split(filePath);
        Node *root = __root;
        int n = path.size();
        for (int i = 0; i < n - 1; i++) {
            if (!((Directory *) root)->mp.count(path[i])) ((Directory *) root)->mp[path[i]] = new Directory(path[i]);
            root = ((Directory *) root)->mp[path[i]];
        }
        if (!((Directory *) root)->mp.count(path[n - 1])) ((Directory *) root)->mp[path[n - 1]] = new File(path[n - 1]);
        root = ((Directory *) root)->mp[path[n - 1]];
        ((File *) root)->content += content;
    }

    string readContentFromFile(string filePath) {
        vector<string> path = split(filePath);
        Node *root = __root;
        for (string &s : path) root = ((Directory *) root)->mp[s];
        return ((File *) root)->content;
    }
};

int main() {
    return 0;
}
