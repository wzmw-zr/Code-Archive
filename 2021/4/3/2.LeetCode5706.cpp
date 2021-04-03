/*************************************************************************
	> File Name: 2.LeetCode5706.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月03日 星期六 22时39分06秒
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

void split_string(vector<string> &words, string &str) {
    for (int i = 0; str[i]; ) {
        while (str[i] && str[i] == ' ') i++;
        string s = "";
        while (str[i] && str[i] != ' ') s += str[i++];
        words.push_back(s);
    }
}

bool check(vector<string> &words1, vector<string> &words2) {
    int n = words1.size();
    int m = words2.size();
    if (words1[0] != words2[0] && words1[n - 1] != words2[m - 1]) return false;
    int l = 0, r = 0;
    if (words1[0] == words2[0]) {
        while (l < m && words1[l] == words2[l]) l++;
    }
    if (words1[n - 1] == words2[m - 1]) {
        while (r < m && words1[n - r - 1] == words2[m - r - 1]) r++;
    }
    if (l == m || r == m || l + r == m) return true;
    return false;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> word1, word2;
    split_string(word1, sentence1);
    split_string(word2, sentence2);
    int n = word1.size(), m = word2.size();
    if (n > m) return check(word1, word2);
    return check(word2, word1);
}

int main() {
    return 0;
}
