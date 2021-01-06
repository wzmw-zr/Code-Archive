/*************************************************************************
	> File Name: 4.LeetCode721.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 01时21分17秒
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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, int> cnt;
    unordered_map<string, string> mp;
    for (auto &x : accounts) {
        for (int i = 1; i < x.size(); i++) {
            cnt[x[i]]++;
            mp[x[i]] = x[0];
        }
    }
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> hash;
    for (auto &&[email, num] : cnt) {
        if (num > 1) ans.push_back(vector<string>({mp[email], email}));
        else {
            if (!hash.count(mp[email])) hash[mp[email]] = vector<string>(0);
            hash[mp[email]].push_back(email);
        }
    }
    for (auto &&[name, emails] : hash) {
        sort(emails.begin(), emails.end());
        vector<string> temp;
        temp.push_back(name);
        for (auto &x : emails) temp.push_back(x);
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
