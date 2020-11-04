/*************************************************************************
	> File Name: 5.LeetCode1455.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 22时06分42秒
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

string get_str(string &sentence, int &ind) {
    string ans = "";
    while (sentence[ind] && sentence[ind] == ' ') ind++;
    while (sentence[ind] && sentence[ind] != ' ') ans += sentence[ind++];
    return ans;
}

int check(string &s1, string &s2) {
    if (s1.size() < s2.size()) return 0;
    return s1.substr(0, s2.size()) == s2 ? 1 : 0;
} 

int isPrefixOfWord(string sentence, string searchWord) {
    int ind = 0, n = sentence.size(), cnt = 0;
    while (ind < n) {
        string temp = get_str(sentence, ind);
        cnt++;
        if (check(temp, searchWord)) return cnt; 
    } 
    return -1;
}

int main() {
    string sentence, searchWord;
    getline(cin, sentence);
    cin >> searchWord;
    cout << isPrefixOfWord(sentence, searchWord) << endl;
    return 0;
}
