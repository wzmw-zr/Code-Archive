/*************************************************************************
	> File Name: 1.LeetCode1418.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月06日 星期二 00时03分29秒
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

vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>> ans;
    set<string> food_names;
    map<int, unordered_map<string, int>> table_menus;
    for (auto order : orders) {
        table_menus[stoi(order[1])][order[2]]++;
        food_names.insert(order[2]);
    }
    ans.push_back({"Table"});
    for (auto food_name : food_names) ans[0].push_back(food_name);
    for (auto &&[table_number, table_menu] : table_menus) {
        vector<string> temp({to_string(table_number)});
        for (auto food_name : food_names) {
            if (table_menu.count(food_name)) temp.push_back(to_string(table_menu[food_name]));
            else temp.push_back("0");
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
