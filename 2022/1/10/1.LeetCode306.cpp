/*************************************************************************
	> File Name: 1.LeetCode306.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月10日 星期一 09时18分11秒
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

string add(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = 0; s1[i]; i++) s1[i] -= '0';
    for (int i = 0; s2[i]; i++) s2[i] -= '0';
    int n = s1.size(), m = s2.size();
    string ans(n + m + 1, 0);
    int ind = 0;
    while (ind < n || ind < m) {
        if ((ind < n) && (ind < m)) {
            ans[ind] += s1[ind] + s2[ind];
        } else if (ind < n) {
            ans[ind] += s1[ind];
        } else {
            ans[ind] += s2[ind];
        }
        if (ans[ind] >= 10) {
            if (ind + 1 == ans.size()) {
                ans.push_back(0);
            }
            ans[ind + 1] += ans[ind] / 10;
            ans[ind] %= 10;
        }
        ind++;
    }
    while (ans.size() > 1 && *ans.rbegin() == 0) {
        ans.erase(prev(ans.end()));
    }
    int l = ans.size();
    for (int i = 0; i < l; i++) ans[i] += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

bool check(string num, int l1, int l2) {
    string first = num.substr(0, l1);
    string second = num.substr(l1, l2);
    int n = num.size();
    int ind = l1 + l2;
    while (ind < n) {
        string third = add(first, second);
        int l = third.size();
        if (l > n - ind) return false;
        string temp = num.substr(ind, l);
        if (third != temp) return false;
        first = second;
        second = third;
        ind += l;
    }
    return true;
}

bool isAdditiveNumber(string num) {
    int n = num.size();
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= n / 2; j++) {
            if (i > (n - i - j) || j > (n - i - j)) continue;
            if (i > 1 && num[0] == '0')  continue;
            if (j > 1 && num[i] == '0') continue;
            if (check(num, i, j)) return true;
        }
    }
    return false;
}

int main() {
    string num;
    cin >> num;
    cout << (isAdditiveNumber(num) ? "True" : "False") << endl;
    return 0;
}
