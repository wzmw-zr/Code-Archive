/*************************************************************************
	> File Name: 2.LeetCode71.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月19日 星期一 22时13分35秒
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

string simplifyPath(string path) {
    vector<string> dirs;
    dirs.push_back("/");
    for (int i = 1; path[i]; ) {
        string temp = "";
        while (path[i] && path[i] == '/') i++;
        while (path[i] && path[i] != '/') temp += path[i++];
        if (temp.size() == 0) continue;
        if (temp == ".") continue;
        if (temp == "..") {
            if (dirs.size() > 1) dirs.pop_back();
            continue;
        }
        dirs.push_back(temp);
    }
    string ans = "";
    int n = dirs.size();
    for (int i = 0; i < n; i++) {
        ans += dirs[i];
        if (i) ans += "/";
    }
    if (ans.size() > 1) ans.pop_back();
    return ans;
}

int main() {
    string path;
    cin >> path;
    cout << simplifyPath(path) << endl;
    return 0;
}
