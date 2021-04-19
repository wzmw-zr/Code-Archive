/*************************************************************************
	> File Name: 1.LeetCode28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月20日 星期二 00时02分42秒
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
    vector<int> next(n, -1);
    for (int i = 1; i < n; i++) {
        int temp = next[i - 1];
        while (temp != -1 && needle[temp + 1] != needle[i]) temp = next[temp];
        if (needle[temp + 1] == needle[i]) next[i] = temp + 1;
    }
    // for (int i = 0; i < n; i++) cout << next[i] << " ";
    // cout << endl;
    int len = -1, ind = 0, h = haystack.size();
    while (ind < h) {
        while (len != -1 && haystack[ind] != needle[len + 1]) len = next[len];
        if (haystack[ind] == needle[len + 1]) len++;
        if (len == n - 1) return ind - len;
        ind++;
    }
    return -1;
}

int main() {
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle) << endl;
    return 0;
}
