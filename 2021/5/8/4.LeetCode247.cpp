/*************************************************************************
	> File Name: 4.LeetCode247.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月08日 星期六 18时45分47秒
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


void dfs(unordered_map<char, char> &mp, vector<string> &ans, string &str, int l, int r) {
    if (l > r) {
        if (str[0] == '0') {
            if (str.size() == 1) 
                ans.push_back(str);
        }
        else ans.push_back(str);
        return ;
    }
    for (auto &&[x, y] : mp) {
        str[l] = x, str[r] = y;
        if (l == r)  {
            if (x != y) continue;
            dfs(mp, ans, str, l + 1, r - 1);
            continue;
        }
        dfs(mp, ans, str, l + 1, r - 1);
    }
}

vector<string> findStrobogrammatic(int n) {
    unordered_map<char, char> mp;
    mp['0'] = '0', mp['1'] = '1', mp['6'] = '9', mp['8'] = '8', mp['9'] = '6';
    vector<string> ans;
    string str(n, ' ');
    dfs(mp, ans, str, 0, n - 1);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;
    auto ans = findStrobogrammatic(n);
    for (auto x : ans) cout << x << endl;
    return 0;
}
