/*************************************************************************
	> File Name: 4.LeetCode208.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月02日 星期三 20时52分00秒
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

struct Node {
    unordered_map<char, Node *> mp;
    bool is_end;
    Node() : is_end(false) {};
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *temp = root;
        for (int i = 0; word[i]; i++) {
            if (!temp->mp.count(word[i])) temp->mp[word[i]] = new Node();
            temp = temp->mp[word[i]];
        }
        temp->is_end = true;
    }
    
    bool search(string word) {
        Node *temp = root;
        for (int i = 0; word[i]; i++) {
            if (!temp->mp.count(word[i])) return false;
            temp = temp->mp[word[i]];
        }
        return temp->is_end;
    }
    
    bool startsWith(string prefix) {
        Node *temp = root;
        for (int i = 0; prefix[i]; i++) {
            if (!temp->mp.count(prefix[i])) return false;
            temp = temp->mp[prefix[i]];
        }
        return true;
    }
};

int main() {
    return 0;
}
