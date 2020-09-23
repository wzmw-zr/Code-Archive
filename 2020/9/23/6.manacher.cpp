/*************************************************************************
	> File Name: 6.manacher.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月23日 星期三 16时00分33秒
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

vector<int> manacher(string s) {
    int n = s.size();
    vector<int> d_1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        d_1[i] = (i > r) ? 1 : min(d_1[l + r - i], r - i + 1);
        while (i + d_1[i] < n && i - d_1[i] >= 0 && s[i + d_1[i]] == s[i - d_1[i]]) d_1[i]++;
        if (i + d_1[i] - 1 > r) l = i - d_1[i] + 1, r = i + d_1[i] - 1;
    }
    return d_1;
}

int main() {
    string temp;
    getline(cin, temp);
    string s = "";
    for (int i = 0; temp[i]; i++) s += "#", s += temp[i];
    s += "#";
    auto ans = manacher(s);
    for (auto &x : ans) cout << x - 1 << " ";
    cout << endl;
    return 0;
}
