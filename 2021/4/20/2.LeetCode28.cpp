/*************************************************************************
	> File Name: 2.LeetCode28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月20日 星期二 00时54分41秒
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

int strStr(string haystack, string needle) {
    int n = needle.size();
    if (n == 0) return 0;
    vector<int> dis(26, n + 1);
    for (int i = 0; i < n; i++) dis[needle[i] - 'a'] = n - i;
    int h = haystack.size();
    int ind = 0;
    while (ind < h) {
        int j = 0;
        while (j < n && haystack[ind + j] && needle[j] == haystack[ind + j]) j++;
        if (j == n) return ind;
        if (ind + n >= h) break;
        ind += dis[haystack[ind + n] - 'a'];
    }
    return -1;
}

int main() {
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle) << endl;
    return 0;
}
