/*************************************************************************
	> File Name: 3.LeetCode5947.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月25日 星期六 22时34分46秒
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


vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size();
    unordered_map<string, unordered_set<string>> mp;
    for (string r : recipes) mp[r] = unordered_set<string>();
    for (int i = 0; i < n; i++) {
        for (string s : ingredients[i]) mp[recipes[i]].insert(s);
    }
    vector<string> ans;
    for (int i = 0; i < supplies.size(); i++) {
        string s = supplies[i];
        vector<string> temp;
        for (auto &&[name, need] : mp) {
            if (!need.count(s)) continue;
            need.erase(s);
            if (need.size()) continue;
            temp.push_back(name);
            ans.push_back(name);
        }
        for (string t : temp) {
            supplies.push_back(t);
            mp.erase(t);
        }
    }
    return ans;
}

int main() {
    return 0;
}
