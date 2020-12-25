/*************************************************************************
	> File Name: 4.LeetCode533.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月25日 星期五 09时22分01秒
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

int findBlackPixel(vector<vector<char>>& picture, int N) {
    int h = picture.size(), w = picture[0].size();
    vector<vector<int>> row(h, vector<int>(0)), column(w, vector<int>(0));
    vector<string> row_string;
    for (int i = 0; i < h; i++) {
        string temp = "";
        for (int j = 0; j < w; j++) temp += picture[i][j];
        row_string.push_back(temp);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (picture[i][j] == 'W') continue;
            row[i].push_back(j);
            column[j].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (row[i].size() - column[j].size()) continue;
            if (!row[i].size()) continue;
            if (row[i].size() != N) continue;
            if (picture[i][j] == 'W') continue;
            string temp = row_string[column[j][0]];
            int flag = 1;
            for (int x : column[j]) {
                if (temp == row_string[x]) continue;
                flag = 0;
                break;
            }
            if (flag) ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
