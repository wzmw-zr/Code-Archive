/*************************************************************************
	> File Name: 1.LeetCode1436.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月01日 星期五 08时35分19秒
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

string destCity(vector<vector<string>> &paths) {
    unordered_map<string, int>  mp;
    for (auto &&path : paths) {
        mp[path[0]]++;
        if (!mp.count(path[1])) mp[path[1]] = 0;
    }
    for (auto &&[name, out_degree] : mp) {
        if (out_degree) continue;
        return name;
    }
    return "";
}

int main() {
    return 0;
}
