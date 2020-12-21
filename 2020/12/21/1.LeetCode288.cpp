/*************************************************************************
	> File Name: 1.LeetCode288.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月21日 星期一 08时06分19秒
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

class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> mp;

    ValidWordAbbr(vector<string>& dictionary) {
        for (string &s : dictionary) {
            int n = s.size();
            string temp = s.substr(0, 1) + to_string(n - 2) + s.substr(n - 1, 1);
            if (!mp.count(temp)) mp[temp] = unordered_set<string>();
            mp[temp].insert(s);
        }
    }

    bool isUnique(string word) {
        int n = word.size();
        string temp = word.substr(0, 1) + to_string(n - 2) + word.substr(n - 1, 1);
        if (!mp.count(temp)) return true;
        if (mp[temp].size() >= 2) return false;
        return word == *mp[temp].begin();
    }
};

int main() {
    return 0;
}
