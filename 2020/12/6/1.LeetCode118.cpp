/*************************************************************************
	> File Name: 1.LeetCode118.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月06日 星期日 06时54分24秒
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

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++) ans.push_back(vector<int>(i, 1));
    for (int i = 2; i < numRows; i++) {
        for (int j = 1; j < ans[i].size() - 1; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}

int main() {
    int numRows;
    cin >> numRows;
    auto ans = generate(numRows);
    for (auto x : ans) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
