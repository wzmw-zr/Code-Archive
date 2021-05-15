/*************************************************************************
	> File Name: 6.LeetCode5744.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 23时04分29秒
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

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int n = box.size(), m = box[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if ((box[i][j] == '.') || (box[i][j] == '*')) continue;
            for (int k = j + 1; k < m; k++) {
                if (box[i][k] == '.') box[i][k - 1] = '.', box[i][k] = '#';
                else break;
            }
        }
    }
    vector<vector<char>> ans(m, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j][n - i - 1] = box[i][j];
        }
    }
    return ans;
}


int main() {
    return 0;
}
