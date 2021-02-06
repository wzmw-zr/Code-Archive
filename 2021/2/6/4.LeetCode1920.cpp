/*************************************************************************
	> File Name: 4.LeetCode1920.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 16时05分04秒
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

int maxAliveYear(vector<int>& birth, vector<int>& death) {
    vector<int> year(105, 0);
    int n = birth.size();
    for (int i = 0; i < n; i++) {
        year[birth[i] - 1900]++;
        year[death[i] + 1 - 1900]--;
    }
    int cnt = year[0];
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        year[i + 1] += year[i];
        if (cnt >= year[i]) continue;
        cnt = year[i];
        ans = i;
    }
    return 1900 + ans;
}

int main() {
    return 0;
}
