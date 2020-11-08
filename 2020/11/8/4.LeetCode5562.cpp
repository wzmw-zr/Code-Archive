/*************************************************************************
	> File Name: 4.LeetCode5562.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 10时39分41秒
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

bool check(unordered_map<int, vector<char>> &mp) {
    for (auto &x : mp) {
        if (x.second.size() == 1) continue;
        return false;
    }
    return true;
}

int minDeletions(string s) {
    unordered_map<char, int> mp_1;
    for (int i = 0; s[i]; i++) mp_1[s[i]]++;
    unordered_map<int, vector<char>> mp_2;
    for (auto &x : mp_1) {
        if (!mp_2.count(x.second)) mp_2[x.second] = vector<char>(0);
        mp_2[x.second].push_back(x.first);
    }
    int cnt = 0;
    while (!check(mp_2)) {
        for (auto &x : mp_2) {
            if (x.second.size() == 1) continue;
            char temp = x.second[0];
            x.second.erase(x.second.begin());
            cnt++;
            if (x.first == 1) continue;
            if (!mp_2.count(x.first - 1)) mp_2[x.first - 1] = vector<char>(0);
            mp_2[x.first - 1].push_back(temp);
        }
    }
    return cnt;
}

int main() {
    string s;
    cin >> s;
    cout << minDeletions(s) << endl;
    return 0;
}
