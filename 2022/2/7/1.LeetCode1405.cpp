/*************************************************************************
	> File Name: 1.LeetCode1405.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月07日 星期一 00时04分52秒
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

using PIC = pair<int, char>;
string longestDiverseString(int a, int b, int c) {
    string s = "";
    vector<PIC> vals;
    if (a) vals.push_back(PIC(a, 'a'));
    if (b) vals.push_back(PIC(b, 'b'));
    if (c) vals.push_back(PIC(c, 'c'));
    while (vals.size()) {
        sort(vals.begin(), vals.end(), greater<PIC>());
        if (s.size() <= 1) {
            s += vals[0].second;
            vals[0].first--;
        } else {
            int l = s.size();
            bool flag = true;
            for (int i = 0; i < vals.size(); i++) {
                if (s[l - 1] == s[l - 2] && s[l - 1] == vals[i].second) {
                    continue;
                }
                s += vals[i].second;
                vals[i].first--;
                flag = false;
                break;
            }
            if (flag) {
                break;
            }
        }
        vector<PIC> temp;
        for (auto &&val : vals) {
            if (val.first == 0) {
                continue;
            }
            temp.push_back(val);
        }
        vals = temp;
    }
    return s;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << longestDiverseString(a, b, c) << endl;
    return 0;
}
