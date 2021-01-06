/*************************************************************************
	> File Name: 3.LeetCode721.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 00时23分36秒
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

typedef pair<int, int> PII;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, unordered_map<string, PII>> hash;
    unordered_map<int, string> mp;
    unordered_map<int, int> cnt;
    int ind = 0;
    for (auto &x : accounts) {
        if (!hash.count(x[0])) hash[x[0]] = unordered_map<string, PII>();
        for (int i = 1; i < x.size(); i++) {
            if (!hash[x[0]].count(x[i])) hash[x[0]][x[i]] = PII(ind, 0);
            hash[x[0]][x[i]].second++;
            cnt[ind]++;
        }
        mp[ind] = x[0];
        ind++;
    }
    vector<vector<string>> ans;
    for (auto &&[name, emails] : hash) {
        vector<string> temp;
        temp.push_back(name);
        for (auto &&[email, detail] : emails) {
            if (detail.second > 1)
                ans.push_back(vector<string>({name, email}));
            else {
                if (cnt[detail.first] == 1) 
                    ans.push_back(vector<string>({name, email}));
                else temp.push_back(email);
            }
        }
        if (temp.size() == 1) continue;
        sort(temp.begin() + 1, temp.end());
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
