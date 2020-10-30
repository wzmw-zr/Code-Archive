/*************************************************************************
	> File Name: 1.LeetCode1624.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月30日 星期五 08时24分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    map<char, pair<int, int>> mp;
    for (int i = 0; s[i]; i++) {
        if (!mp.count(s[i])) mp[s[i]] = pair<int, int>(i, i);
        mp[s[i]].second = i;
    }
    int ans = -1;
    for (auto &x : mp) {
        ans = max(ans, x.second.second - x.second.first - 1);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << maxLengthBetweenEqualCharacters(s) << endl;
    return 0;
}
