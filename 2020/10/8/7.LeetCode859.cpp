/*************************************************************************
	> File Name: 7.LeetCode859.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 19时56分21秒
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

bool diff_check(string &A, string &B) {
    int diff_cnt = 0;
    map<char, int> mp;
    for (int i = 0; A[i]; i++) diff_cnt += (A[i] == B[i] ? 0 : 1);
    if (diff_cnt != 2) return false;
    for (char &c : A) mp[c]++;
    for (char &c : B) {
        if (mp[c]--) return false;
    }
    return true;
}

bool same_check(string &A, string &B) {
    map<char, int> mp;
    for (char &c : A) mp[c]++;
    for (auto &x : mp) {
        if (x.second & 1) continue;
        return true;
    }
    return false;
}

bool buddyStrings(string A, string B) {
    if (A.size() - B.size()) return false;
    if (A != B) return diff_check(A, B);
    return same_check(A, B);
}

int main() {
    string A, B;
    cin >> A >> B;
    cout << (buddyStrings(A, B) ? "Yes" : "No") << endl;
    return 0;
}
