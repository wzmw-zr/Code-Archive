/*************************************************************************
	> File Name: 1.LeetCode243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月10日 星期六 00时08分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    vector<int> pos1, pos2;
    int n = wordsDict.size();
    for (int i = 0; i < n; i++) {
        if (wordsDict[i] == word1) pos1.push_back(i);
        if (wordsDict[i] == word2) pos2.push_back(i);
    }
    int mmin = INT32_MAX;
    for (int x : pos1) {
        for (int y : pos2) mmin = min(mmin, abs(x - y));
    }
    return mmin;
}

int main() {
    return 0;
}
