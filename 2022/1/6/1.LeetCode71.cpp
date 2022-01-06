/*************************************************************************
	> File Name: 1.LeetCode71.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月06日 星期四 09时45分54秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string simplifyPath(string path) {
    int ind = 0;
    vector<string> seg;
    while (path[ind]) {
        while (path[ind] && path[ind] == '/') ind++;
        string temp = "";
        while (path[ind] && path[ind] != '/') temp += path[ind++];
        if (temp != "") {
            if (temp == ".") continue;
            else if (temp == "..") {
                if (seg.size()) seg.pop_back();
            } else seg.push_back(temp);
        }
    }
    string ans = "";
    for (string s: seg) ans += "/" + s;
    return ans == "" ? "/" : ans;
}

int main() {
    string path;
    cin >> path;
    cout << simplifyPath(path) << endl;
    return 0;
}
