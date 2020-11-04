/*************************************************************************
	> File Name: 2.LeetCode127.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 00时49分36秒
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
    int level;

    Node() = default;
    Node(string word, int level) : word(word), level(level) {}
};

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st, check;
    queue<Node> que;
    for (auto &x : wordList) st.insert(x);
    st.insert(beginWord);
    if (!st.count(endWord)) return 0;
    que.push({beginWord, 1});
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        if (temp.word == endWord) return temp.level;
        check.insert(temp.word);
        for (int i = 0; temp.word[i]; i++) { 
            string word_t = temp.word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == temp.word[i]) continue;
                word_t[i] = c;
                if (!st.count(word_t) || check.count(word_t)) continue;
                que.push({word_t, temp.level + 1});
            }
        }
    }
    return 0;
}

int main() {
    string beginWord, endWord, word;
    vector<string> wordList;
    cin >> beginWord >> endWord;
    while (cin >> word) wordList.push_back(word);
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
