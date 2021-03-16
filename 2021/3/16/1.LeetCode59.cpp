/*************************************************************************
	> File Name: 1.LeetCode59.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月16日 星期二 00时01分57秒
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

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int num = 1;
    int x = 0, y = 0;
    while (n) {
        if (n == 1) {
            ans[x][y] = num++;
            break;
        }
        for (int i = 0; i < n; i++) ans[x][y + i] = num++;
        for (int i = 1; i < n; i++) ans[x + i][y + n - 1] = num++;
        for (int i = n - 2; i >= 0; i--) ans[x + n - 1][y + i] = num++;
        for (int i = n - 2; i > 0; i--) ans[x + i][y] = num++;
        x++, y++;
        n -= 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    auto ans = generateMatrix(n);
    for (auto &x : ans) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
