/*************************************************************************
	> File Name: 1.LeetCode842.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月08日 星期二 07时27分46秒
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

int check(string &S, int len_1, int len_2) {
    int n = S.size(), ind = len_1 + len_2;
    if (ind >= n) return 0;
    long num_1 = stol(S.substr(0, len_1));
    long num_2 = stol(S.substr(len_1, len_2));
    long num_3;
    while (ind < n) {
        num_3 = num_1 + num_2;
        string s_1 = to_string(num_3);
        if (ind + s_1.size() > n) return 0;
        string s_2 = S.substr(ind, s_1.size());
        if (s_1 != s_2) return 0;
        num_1 = num_2;
        num_2 = num_3;
        ind += s_1.size();
    }
    return 1;
}

vector<int> get_ans(string &S, int len_1, int len_2) {
    int n = S.size(), ind = len_1 + len_2;
    vector<int> ans;
    if (ind >= n) return vector<int>(0);
    long num_1 = stol(S.substr(0, len_1));
    long num_2 = stol(S.substr(len_1, len_2));
    long num_3;
    if (num_1 > INT32_MAX) return vector<int>(0);
    if (num_2 > INT32_MAX) return vector<int>(0);
    ans.push_back((int) num_1);
    ans.push_back((int) num_2);
    while (ind < n) {
        num_3 = num_1 + num_2;
        if (num_3 > INT32_MAX) return vector<int>(0);
        ans.push_back((int) num_3);
        string s_1 = to_string(num_3);
        if (ind + s_1.size() > n) return vector<int>(0);
        string s_2 = S.substr(ind, s_1.size());
        if (s_1 != s_2) return vector<int>(0);
        num_1 = num_2;
        num_2 = num_3;
        ind += s_1.size();
    }
    return ans;
}

vector<int> splitIntoFibonacci(string S) {
    int n = S.size();
    vector<int> ans;
    for (int i = 1; i <= min(10, n / 2); i++) {
        if (i > 1 && S[0] == '0') break; 
        for (int j = 1; j <= min(10, (n - i) / 2); j++) {
            if (j > 1 && S[i] == '0') break; 
            if (!check(S, i, j)) continue;
            ans = get_ans(S, i, j);
            break;
        }
        if (ans.size()) break;
    }
    return ans;
}

int main() {
    string S;
    cin >> S;
    auto ans = splitIntoFibonacci(S);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
