/*************************************************************************
	> File Name: 4.LeetCode1920.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月05日 星期二 22时05分52秒
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

bool dfs(string &beginWord, string &endWord, vector<bool> &check, int ind, vector<string> &path, int &cnt, vector<string> &ans, unordered_set<string> &st) {
    if (cnt == 0) {
        ans = path;
        return true;
    }
    char temp = beginWord[ind];
    beginWord[ind] = endWord[ind];
    if (!st.count(beginWord)) {
        beginWord[ind] = temp;
        return false;
    }
    check[ind] = true;
    bool res = false;
    cnt--;
    path.push_back(beginWord);
    for (int i = 0; beginWord[i]; i++) {
        if (check[i]) continue;
        res |= dfs(beginWord, endWord, check, i, path, cnt, ans, st);
    }
    path.pop_back();
    cnt++;
    check[ind] = false;
    beginWord[ind] = temp;
    return res;
}

vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st;
    int n = beginWord.size();
    int cnt = 0;
    vector<bool> check(n, false);
    for (int i = 0; i < n; i++) {
        if (beginWord[i] == endWord[i]) check[i] = true;
        else {
            check[i] = false;
            cnt++;
        }
    }
    for (string &s : wordList) st.insert(s);
    vector<string> ans;
    vector<string> path;
    for (int i = 0; beginWord[i]; i++) {
        if (check[i]) continue;
        path.push_back(beginWord);
        if (dfs(beginWord, endWord, check, i, path, cnt, ans, st)) return ans;
        path.pop_back();
    }
    return ans;
}

int main() {
    return 0;
}
