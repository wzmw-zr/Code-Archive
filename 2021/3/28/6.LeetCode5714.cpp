/*************************************************************************
	> File Name: 6.LeetCode5714.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 10时40分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> mp;
    for (auto && x : knowledge) mp[x[0]] = x[1];
    string ans = "";
    for (int i = 0; s[i];) {
        if (s[i] >= 'a' && s[i] <= 'z') ans += s[i++];
        else {
            i++;
            string temp = "";
            while (s[i] != ')') temp += s[i++];
            i++;
            if (mp.count(temp)) ans += mp[temp];
            else ans += '?';
        }
    }
    return ans;
}

int main() {
    return 0;
}
