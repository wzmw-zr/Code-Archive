/*************************************************************************
	> File Name: 3.LeetCode531.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月25日 星期五 09时12分40秒
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

int findLonelyPixel(vector<vector<char>>& picture) {
    int h = picture.size(), w = picture[0].size();
    unordered_map<int, int> row, column;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (picture[i][j] == 'W') continue;
            row[i]++, column[j]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (picture[i][j] == 'W' || (picture[i][j] == 'B' && (row[i] >= 2 || column[j] >= 2))) continue;
            ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
