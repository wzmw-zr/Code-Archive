/*************************************************************************
	> File Name: 6.LeetCode721.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 08时30分21秒
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

struct UnionSet {
    int n;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    unordered_map<string, int> hash;
    unordered_map<int, string> mp;
    int ind = 0;
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (hash.count(accounts[i][j])) continue;
            hash[accounts[i][j]] = ind;
            mp[ind++] = accounts[i][0];
        }
    }
    UnionSet u(ind);
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) u.merge(hash[accounts[i][1]], hash[accounts[i][j]]);
    }
    unordered_map<int, vector<string>> id_to_emails;
    for (auto &&[email, ind] : hash) {
        int root = u.get(hash[email]);
        if (!id_to_emails.count(root)) id_to_emails[root] = vector<string>(0);
        id_to_emails[root].push_back(email);
    }
    vector<vector<string>> ans;
    for (auto &&[id, emails] : id_to_emails) {
        sort(emails.begin(), emails.end());
        vector<string> temp;
        temp.push_back(mp[id]);
        for (auto &x : emails) temp.push_back(x);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
