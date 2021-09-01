/*************************************************************************
	> File Name: 1.LeetCode165.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月01日 星期三 10时05分54秒
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

vector<int> split(string &version) {
    vector<int> nums;
    int ind = 0;
    while (version[ind]) {
        string s = "";
        while (version[ind] && version[ind] != '.') s += version[ind++];
        if (version[ind]) ind++;
        if (s.size()) nums.push_back(stoi(s));
    }
    return nums;
}

int compareVersion(string version1, string version2) {
    vector<int> nums1 = split(version1);
    vector<int> nums2 = split(version2);
    int len_1 = nums1.size(), len_2 = nums2.size();
    int n = max(len_1, len_2);
    if (len_1 < len_2) {
        for (int i = 0; i < len_2 - len_1; i++) nums1.push_back(0);
    } else {
        for (int i = 0; i < len_1 - len_2; i++) nums2.push_back(0);
    }
    #if 0
    for (auto x : nums1) cout << x << " ";
    cout << endl;
    for (auto x : nums2) cout << x << " ";
    cout << endl;
    #endif
    for (int i = 0; i < n; i++) {
        if (nums1[i] == nums2[i]) continue;
        if (nums1[i] < nums2[i]) return -1;
        return 1;
    }
    return 0;
}

int main() {
    string version1, version2;
    cin >> version1 >> version2;
    cout << compareVersion(version1, version2) << endl;
    return 0;
}
