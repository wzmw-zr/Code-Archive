/*************************************************************************
	> File Name: 6.LeetCode1592.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月06日 星期二 22时18分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

string reorderSpaces(string text) {
    vector<string> words;
    int ind = 0, blank_cnt = 0;
    while (text[ind]) {
        while (text[ind] && text[ind] == ' ') ind++, blank_cnt++;
        string s = "";
        if (text[ind]) { 
            while (text[ind] && text[ind] != ' ') {
                s += text[ind];
                ind++;
            }
            words.push_back(s);
        }
    }
    int s_num = words.size();
    string ans = "";
    if (s_num == 1) {
        ans += words[0];
        for (int i = 0; i < blank_cnt; i++) ans += ' ';
    } else {
        int dis = blank_cnt / (s_num - 1);
        int rest = blank_cnt - dis * (s_num - 1);
        int i = 0;
        for (i = 0; i < s_num - 1; i++) {
            ans += words[i];
            for (int j = 0; j < dis; j++) ans += ' ';
        }
        ans += words[i];
        for (int j = 0; j < rest; j++) ans += ' ';
    }
    return ans;
}

int main() {
    string text;
    getline(cin, text);
    cout << reorderSpaces(text) << endl;
    return 0;
}
