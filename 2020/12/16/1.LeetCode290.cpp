/*************************************************************************
	> File Name: 1.LeetCode290.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月16日 星期三 09时15分18秒
 ************************************************************************/

#include<iostream>
#include<sstream>
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

bool wordPattern(string pattern, string s) {
    istringstream str(s);
    vector<string> words;
    string temp;
    while (str >> temp) words.push_back(temp);
    if (pattern.size() - words.size()) return false;
    int n = pattern.size();
    unordered_map<string, char> mp_1;
    unordered_map<char, string> mp_2;
    for (int i = 0; i < n; i++) {
        if (!mp_1.count(words[i]) && !mp_2.count(pattern[i])) {
            mp_1[words[i]] = pattern[i]; 
            mp_2[pattern[i]] = words[i];
            continue;
        } 
        if (mp_1.count(words[i]) && mp_2.count(pattern[i])) {
            if (mp_1[words[i]] == pattern[i] && mp_2[pattern[i]] == words[i]) continue;
            return false;
        }
        return false;
    }
    return true;
}

int main() {
    string pattern, s;
    cin >> pattern;
    getchar();
    getline(cin, s);
    cout << pattern << endl;
    cout << s << endl;
    cout << (wordPattern(pattern, s) ? "Yes" : "No") << endl;
    return 0;
}
