/*************************************************************************
	> File Name: 2.LeetCode1417.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月03日 星期二 07时39分14秒
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

string reformat(string s) {
    vector<char> char_v, num_v;
    string ans = "";
    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') num_v.push_back(s[i]);
        else char_v.push_back(s[i]);
    }
    if (abs((int) char_v.size() - (int) num_v.size()) > 1) return "";
    if (char_v.size() == num_v.size()) {
        for (int i = 0; i < char_v.size(); i++) 
            ans += char_v[i], ans += num_v[i];
    } else if (char_v.size() > num_v.size()) { 
        for (int i = 0; i < num_v.size(); i++) 
            ans += char_v[i], ans += num_v[i];
        ans += char_v[char_v.size() - 1];
    } else {
        for (int i = 0; i < char_v.size(); i++) 
            ans += num_v[i], ans += char_v[i];
        ans += num_v[num_v.size() - 1];
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << reformat(s) << endl;
    return 0;
}
