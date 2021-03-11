/*************************************************************************
	> File Name: 4.LeetCode267.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月11日 星期四 21时55分29秒
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

void dfs(vector<int> &cnt, unordered_set<string> &ans, string &data, int &n, int res) {
    for (int i = 0; i < 26; i++) cout << cnt[i] << " ";
    cout << endl;
    if (res == 0) {
        cout << res << " " << data << endl;
        ans.insert(data);
        return ;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] >= 2) {
            int left = (n - res) / 2;
            int right = n - 1 - left;
            data[left] = i + 'a';
            data[right] = i + 'a';
            cnt[i] -= 2;
            dfs(cnt, ans, data, n, res - 2);
            cnt[i] += 2;
        } else {
            data[n / 2] = i + 'a';
            cnt[i]--;
            dfs(cnt, ans, data, n, res - 1);
            cnt[i]++;
        }
    }

}

vector<string> generatePalindromes(string s) {
    unordered_set<string> ans;
    vector<string> res;
    int n = s.size();
    vector<int> cnt(26, 0);
    for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
    int odd_cnt = 0;
    for (int i = 0; i < 26; i++) odd_cnt += cnt[i] & 1;
    if (odd_cnt > 1) return res;
    string data(n, ' ');
    dfs(cnt, ans, data, n, n);
    for (auto str : ans) res.push_back(str);
    return res;
}

int main() {
    string s;
    cin >> s;
    auto ans = generatePalindromes(s);
    for (auto &x : ans) cout << x << endl;
    return 0;
}
