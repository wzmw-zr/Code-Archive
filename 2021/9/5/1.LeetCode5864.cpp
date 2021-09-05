/*************************************************************************
	> File Name: 1.LeetCode5864.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月05日 星期日 10时36分25秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end());
    vector<int> mmax(1e5 + 10, 0);
    int ans = 0;
    int n = properties.size();
    for (int i = n - 1; i >= 0; i--) mmax[properties[i][0]] = max(properties[i][1], mmax[properties[i][0]]);
    for (int i = 1e5; i >= 1; i--) mmax[i] = max(mmax[i], mmax[i + 1]);
    for (int i = 0; i < n; i++) {
        if (mmax[properties[i][0] + 1] > properties[i][1]) ans++;
    }
    return ans;
}

int main() {
    return 0;
}
