/*************************************************************************
	> File Name: 1.LeetCode68.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月09日 星期四 08时18分58秒
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

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    int l = 0, r = 0;
    vector<string> ans;
    while (l < n) {
        int len = 0;
        while ((r < n) && (len + (r - l) + words[r].size() <= maxWidth)) {
            len += words[r].size();
            r++;
        }
        string s = "";
        if (r != n) {
            int res = maxWidth - len;
            int inter = max(1, r - 1 - l);
            int avg = res / inter;
            int extra = res - avg * inter;
            for (int i = l; i < r; i++, inter--) {
                s += words[i];
                if (inter) {
                    for (int j = 0; j < avg; j++) s += ' ';
                    if (extra) s += ' ', extra--;
                }
            }
            ans.push_back(s);
        } else {
            for (int i = l; i < r; i++) {
                if (i - l) s += ' ';
                s += words[i];
            }
            while (s.size() < maxWidth) s += ' ';
            ans.push_back(s);
        }
        l = r;
    }
    return ans;
}

int main() {
    int maxWidth;
    string s;
    vector<string> words;
    cin >> maxWidth;
    while (cin >> s) words.push_back(s);
    auto ans = fullJustify(words, maxWidth);
    for (auto x : ans) cout << x << "\n";
    return 0;
}
