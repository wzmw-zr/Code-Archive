/*************************************************************************
	> File Name: 1.LeetCode139.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月25日 星期四 20时12分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool check(string s, string res, vector<string> &wordDict) {
    if (s == res) return true;
    if (res.size() > s.size()) return false;
    for (int i = 0; i < wordDict.size(); i++) {
        if (check(s, res + wordDict[i], wordDict)) return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    return check(s, "", wordDict);
}


int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<string> wordDict;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        wordDict.push_back(tmp);
    }
    if (wordBreak(s, wordDict)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
