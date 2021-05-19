/*************************************************************************
	> File Name: 1.LeetCode692.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月20日 星期四 00时01分16秒
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
    string word;
    int cnt;

    Node() = default;
    Node(string word, int cnt) : word(word), cnt(cnt) {}

    bool operator<(const Node &that) const {
        return this->cnt == that.cnt ? this->word < that.word : this->cnt > that.cnt;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    for (string w : words) mp[w]++;
    vector<Node> nodes;
    for (auto &&[word, cnt] : mp) nodes.push_back(Node(word, cnt));
    sort(nodes.begin(), nodes.end());
    vector<string> ans;
    for (int i = 0; i < k; i++) ans.push_back(nodes[i].word);
    return ans;
}

int main() {
    return 0;
}
