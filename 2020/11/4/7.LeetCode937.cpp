/*************************************************************************
	> File Name: 7.LeetCode937.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 22时35分14秒
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

struct Node {
    string pre, rest;
    Node() = default;
    Node(string pre, string rest) : pre(pre), rest(rest) {}
};

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<Node> str_v, num_v;
    vector<string> ans;
    for (auto &x : logs) {
        int ind = x.find(' ', 0);
        int second_ind = x.find(' ', ind + 1);
        string pre = x.substr(0, ind);
        string second_word;
        string rest;
        if (second_ind == string::npos) {
            second_word = x.substr(ind + 1);   
            rest = x.substr(ind);
        } else {
            second_word = x.substr(ind + 1, second_ind - ind - 1);
            rest = x.substr(ind);
        }
        int flag = 0;
        for (char &c : second_word) {
            if (c >= 'a' && c <= 'z') {
                flag = 1;
                break;
            } 
        }
        if (flag) str_v.push_back({pre, rest});
        else num_v.push_back({pre, rest});
    }
    sort(str_v.begin(), str_v.end(), [](Node &a, Node &b){ return a.rest == b.rest ? a.pre < b.pre : a.rest < b.rest; });
    for (auto &x : str_v) ans.push_back(x.pre + x.rest);
    for (auto &x : num_v) ans.push_back(x.pre + x.rest);
    return ans;
}

int main() {
    string log;
    vector<string> logs;
    while (getline(cin, log)) logs.push_back(log);
    auto ans = reorderLogFiles(logs);
    for (auto &x : ans) cout << x << endl;
    return 0;
}
