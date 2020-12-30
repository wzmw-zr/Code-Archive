/*************************************************************************
	> File Name: 4.LeetCode1899.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月30日 星期三 16时49分05秒
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

void split(string &s, string &name, string &num) {
    int ind = 0;
    while (s[ind] != '(') name += s[ind++];
    ind++;
    while (s[ind] != ')') num += s[ind++];
}

void get_name(string &s, string &name_1, string &name_2) {
    int ind = 1;
    while (s[ind] != ',') name_1 += s[ind++];
    ind++;
    while (s[ind] != ')') name_2 += s[ind++];
}

struct Unionset {
    int n;
    vector<int> fa;
    Unionset() = default;
    Unionset(int n) : n(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y, unordered_map<string, int> &cnt, unordered_map<int, string> &mp) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        if (mp[a] < mp[b]) {
            cnt[mp[a]] += cnt[mp[b]];
            fa[b] = a;
        } else {
            cnt[mp[b]] += cnt[mp[a]];
            fa[a] = b;
        }
    }
};

vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
    unordered_map<string, int> hash;
    unordered_map<string, int> cnt;
    unordered_map<int, string> mp;
    int ind = 0;
    for (string &s : names) {
        string name = "", num = "";
        split(s, name, num);
        mp[ind] = name;
        hash[name] = ind++;
        cnt[name] = stoi(num);
    }
    for (string &s : synonyms) {
        string name_1 = "", name_2 = "";
        get_name(s, name_1, name_2);
        if (!hash.count(name_1)) {
            mp[ind] = name_1;
            hash[name_1] = ind++;
            cnt[name_1] = 0;
        }
        if (!hash.count(name_2)) {
            mp[ind] = name_2;
            hash[name_2] = ind++;
            cnt[name_2] = 0;
        }
    }
    Unionset u(ind);
    for (string &s : synonyms) {
        string name_1 = "", name_2 = "";
        get_name(s, name_1, name_2);
        u.merge(hash[name_1], hash[name_2], cnt, mp);
    }
    vector<string> ans;
    for (int i = 0; i < ind; i++) {
        if (i != u.fa[i]) continue;
        ans.push_back(mp[i] + "(" + to_string(cnt[mp[i]])  + ")");
    }
    return ans;
}

int main() {
    return 0;
}
