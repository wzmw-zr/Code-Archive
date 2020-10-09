/*************************************************************************
	> File Name: 3.LeetCode293.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月09日 星期五 11时12分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> generatePossibleNextMoves(string s) {
    vector<string> ans(0);
    cout << (int) s.size() << endl;
    cout << (int) s.size() - 1 << endl;
    for (int i = 0; i < (int) s.size() - 1; i++) {
        if (s[i] == '+' && s[i + 1] == '+') {
            s[i] = '-', s[i + 1] = '-';
            ans.push_back(s);
            s[i] = '+', s[i + 1] = '+';
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    auto ans = generatePossibleNextMoves(s);
    for (string &x : ans) cout << x << endl;
    return 0;
}
