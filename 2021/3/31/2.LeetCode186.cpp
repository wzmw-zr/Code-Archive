/*************************************************************************
	> File Name: 2.LeetCode186.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月31日 星期三 00时15分22秒
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

void reverse_vec(vector<char> &s, int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        l++, r--;
    }
}

void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());
    int n = s.size();
    int l = 0, r = 0;
    while (r < n) {
        while (r < n && s[r] == ' ') r++;
        l = r;
        while (r < n && s[r] != ' ') r++;
        reverse_vec(s, l, r - 1);
    }
}

int main() {
    return 0;
}
