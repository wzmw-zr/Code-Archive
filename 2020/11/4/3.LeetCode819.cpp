/*************************************************************************
	> File Name: 3.LeetCode819.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 08时06分14秒
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

string split(string &paragraph, int &ind) {
    string ans = "";
    while (paragraph[ind] && !(paragraph[ind] >= 'a' && paragraph[ind] <= 'z')) ind++;
    while (paragraph[ind] && (paragraph[ind] >= 'a' && paragraph[ind] <= 'z')) ans += paragraph[ind++];
    return ans;
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> banned_st;
    unordered_map<string, int> allowed_mp;
    for (auto &x : banned) banned_st.insert(x);
    for (char &c : paragraph) {
        if (c >= 'A' && c <= 'Z') c += 32;
    }
    int ind = 0, n = paragraph.size();
    while (ind < n) {
        string temp = split(paragraph, ind);
        if (temp.size() == 0) continue;
        if (banned_st.count(temp)) continue;
        allowed_mp[temp]++;
    }
    int cnt = 0;
    string ans = "";
    for (auto &x : allowed_mp) {
        if (cnt >= x.second) continue;
        cnt = x.second;
        ans = x.first;
    }
    return ans;
}

int main() {
    return 0;
}
