/*************************************************************************
	> File Name: 1.LeetCode800.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 08时20分22秒
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

void init(unordered_map<char, int> &mp) {
    for (int i = 0, j = '0'; i <= 9; i++, j++) mp[j] = i;
    for (int i = 10, j = 'a'; i <= 15; i++, j++) mp[j] = i;
}

void dfs(string &color, string path, int ind, string &ans, int &mmax, unordered_map<char, int> &mp) {
    if (ind == 3) {
        int n_1 = mp[color[1]] * 16 + mp[color[2]] - mp[path[0]] * 16 - mp[path[0]];
        int n_2 = mp[color[3]] * 16 + mp[color[4]] - mp[path[1]] * 16 - mp[path[1]];
        int n_3 = mp[color[5]] * 16 + mp[color[6]] - mp[path[2]] * 16 - mp[path[2]];
        int temp = (n_1 * n_1 + n_2 * n_2 + n_3 * n_3) * -1;
        if (mmax < temp) {
            ans = path;
            mmax = temp;
        }
        return ;
    }
    for (auto &x : mp) dfs(color, path + x.first, ind + 1, ans, mmax, mp);
}

string similarRGB(string color) {
    unordered_map<char, int> mp;
    init(mp);
    int mmax = INT32_MIN;
    string ans = "", path = "", res = "#";
    dfs(color, path, 0, ans, mmax, mp);
    res += ans[0], res += ans[0], res += ans[1], res += ans[1], res += ans[2], res += ans[2];
    return res;
}

int main() {
    string color;
    cin >> color;
    cout << similarRGB(color) << endl;
    return 0;
}
