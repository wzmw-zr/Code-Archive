/*************************************************************************
	> File Name: 4.LeetCode893.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月03日 星期二 08时22分26秒
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

bool issame(string &x, string &y) {
    if (x.size() - y.size()) return false;
    map<char, int> even, odd;
    for (int i = 0; x[i]; i++) {
        if (i & 1) odd[x[i]]++;
        else even[x[i]]++;
    }
    for (int i = 0; y[i]; i++) {
        if (i & 1) {
            if (odd[y[i]] == 0) return false;
            odd[y[i]]--;
        } else {
            if (even[y[i]] == 0) return false;
            even[y[i]]--;
        }
    }
    return true;
}

int numSpecialEquivGroups(vector<string>& A) {
    vector<string> s_v;
    for (string &x : A) {
        int flag = 0;
        for (string &y : s_v) {
            if (!issame(x, y)) continue;
            flag = 1;
            break;
        }
        if (flag) continue;
        s_v.push_back(x);
    }
    return s_v.size();
}

int main() {
    string word;
    vector<string> A;
    while (cin >> word) A.push_back(word);
    cout << numSpecialEquivGroups(A) << endl;
    return 0;
}
