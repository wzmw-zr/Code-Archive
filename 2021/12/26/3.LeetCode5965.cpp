/*************************************************************************
	> File Name: 3.LeetCode5965.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月26日 星期日 10时52分37秒
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

vector<long long> getDistances(vector<int>& arr) {
    unordered_map<int, vector<long>> mp;
    unordered_map<int, int> cnts;
    unordered_map<int, long> dis;
    vector<long long> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (!mp.count(arr[i])) mp[arr[i]] = vector<long>();
        mp[arr[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (!cnts.count(arr[i])) {
            cnts[arr[i]] = 0;
            long temp = 0;
            int m = mp[arr[i]].size();
            for (int j = 1; j < m; j++) temp += mp[arr[i]][j] - mp[arr[i]][0];
            ans.push_back(temp);
            dis[arr[i]] = temp;
        } else {
            int ind = cnts[arr[i]];
            int m = mp[arr[i]].size();
            long temp = dis[arr[i]];
            temp += (mp[arr[i]][ind] - mp[arr[i]][ind - 1]) * (2 * ind - m);
            ans.push_back(temp);
            dis[arr[i]] = temp;
        }
        cnts[arr[i]]++;
    }
    return ans;
}

int main() {
    return 0;
}
