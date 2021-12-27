/*************************************************************************
	> File Name: 1.LeetCode825.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月27日 星期一 09时41分00秒
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

int find_first(vector<int> &ages, int num) {
    int l = 0, r = ages.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ages[mid] < num) l = mid + 1;
        else r = mid;
    }
    return l;
}

int find_last(vector<int> &ages, int num) {
    int l = 0, r = ages.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (ages[mid] <= num) l = mid;
        else r = mid - 1;
    }
    return l;
}

int numFriendRequests(vector<int>& ages) {
    sort(ages.begin(), ages.end());
    int n = ages.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num = ages[i] / 2 + 8;
        if (num > ages[i]) continue;
        int left = find_first(ages, num);
        int right = find_last(ages, ages[i]);
        ans += right - left;
    }
    return ans;
}

int main() {
    vector<int> ages;
    int n;
    while (cin >> n) ages.push_back(n);
    cout << numFriendRequests(ages) << endl;
    return 0;
}
