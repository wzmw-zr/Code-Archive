/*************************************************************************
	> File Name: 7.LeetCode734.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 08时56分44秒
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

bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
    if (sentence1.size() - sentence2.size()) return false;
    unordered_map<string, unordered_set<string>> mp;
    for (auto &x : similarPairs) {
        if (!mp.count(x[0])) {
            mp[x[0]] = unordered_set<string>();
            mp[x[0]].insert(x[0]);
        }
        if (!mp.count(x[1])) {
            mp[x[1]] = unordered_set<string>();
            mp[x[1]].insert(x[1]);
        }
        mp[x[0]].insert(x[1]);
        mp[x[1]].insert(x[0]);
    }
    for (int i = 0; i < sentence1.size(); i++) {
        if (!mp.count(sentence1[i])) {
            if (sentence1[i] == sentence2[i]) continue;
            return false;
        }
        if (mp[sentence1[i]].count(sentence2[i])) continue;
        return false;
    }
    return true;
}

int main() {
    return 0;
}
