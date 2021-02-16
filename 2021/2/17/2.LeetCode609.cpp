/*************************************************************************
	> File Name: 2.LeetCode609.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月17日 星期三 00时13分00秒
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

vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    for (auto &path : paths) {
        string dir;
        int l = 0, r = 0;
        while (path[r] && path[r] != ' ') r++;
        dir = path.substr(l, r - l);
        l = ++r;
        while (path[r]) {
            while (path[r] && path[r] != '(') r++;
            string name = dir + "/" + path.substr(l, r - l);
            l = ++r;
            while (path[r] && path[r] != ')') r++;
            string content = path.substr(l, r - l);
            if (!mp.count(content)) mp[content] = vector<string>(0);
            mp[content].push_back(name);
            if (!path[r + 1]) break;
            l = r = r + 2;
        }
    }
    for (auto &&[content, files] : mp) {
        if (files.size() == 1) continue;
        ans.push_back(files);
    }
    return ans;
}

int main() {
    return 0;
}
