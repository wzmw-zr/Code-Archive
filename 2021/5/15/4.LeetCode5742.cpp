/*************************************************************************
	> File Name: 4.LeetCode5742.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 22时40分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string sortSentence(string s) {
    vector<string> strs;
    int ind = 0;
    while (s[ind]) {
        string temp = "";
        while (s[ind] && (s[ind] != ' ')) temp += s[ind++];
        strs.push_back(temp);
        if (s[ind]) ind++;
    }
    sort(strs.begin(), strs.end(), [](string &a, string &b){
        return *a.rbegin() < *b.rbegin();
    });
    string ans = "";
    int n = strs.size();
    for (int i = 0; i < n; i++) {
        if (i) ans += " ";
        int l = strs[i].size();
        for (int j = 0; j < l - 1; j++) ans += strs[i][j];
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << sortSentence(s) << endl;
    return 0;
}
