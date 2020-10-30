/*************************************************************************
	> File Name: 3.LeetCode800.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月30日 星期五 22时43分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

vector<string> c;
map<char, int> mp;

void dfs(string &color, string &ans, string str, int &dis) {
    if (color.size() == str.size()) {
        int dis_t = -1 * (pow(mp[color[0]] * 16 + mp[color[1]] - mp[str[0]] * 16 - mp[str[1]], 2));
        if (dis < dis_t) {
            dis = dis_t;
            ans = str;
        }
        return ;
    }
    for (int i = 0; i < 16; i++) dfs(color, ans, str + c[i], dis);
}

string nearest(string color) {
    string ans = "";
    int dis = INT32_MIN;
    dfs(color, ans, "", dis);
    return ans;
}

string similarRGB(string color) {
    string temp = "0";
    for (int i = 0; i < 10; i++) {
        c.push_back(temp);
        mp[temp[0]] = i;
        temp[0]++;
    }
    temp = "a";
    for (int i = 0; i < 6; i++) {
        c.push_back(temp);
        mp[temp[0]] = 10 + i;
        temp[0]++;
    }
    string ans = "#";
    ans += nearest(color.substr(1, 2));
    ans += nearest(color.substr(3, 2));
    ans += nearest(color.substr(5, 2));
    return ans;
}

int main() {
    string color;
    cin >> color;
    cout << similarRGB(color) << endl;
    return 0;
}
