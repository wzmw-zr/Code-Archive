/*************************************************************************
	> File Name: 2.LeetCode1271.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 08时45分42秒
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

bool check(string &ans) {
    for (auto &x : ans) {
        if (x >= '2' && x <= '9') return false;
    }
    return true;
}

string toHexspeak(string num) {
    long n = stol(num);
    unordered_map<char, int> mp;
    for (int i = 0, j = '0'; i <= 9; i++, j++) mp[i] = j;
    for (int i = 10, j = 'A'; i <= 15; i++, j++) mp[i] = j;
    mp[0] = 'O', mp[1] = 'I';
    vector<int> res;
    while (n) {
        res.push_back(n % 16);
        n /= 16;
    }
    reverse(res.begin(), res.end());
    string ans = "";
    for (auto &x : res) {
        if (x >= 2 && x <= 9) return "ERROR";
        ans += mp[x];   
    }
    return ans;
}

int main() {
    string num;
    cin >> num;
    cout << toHexspeak(num) << endl;
    return 0;
}
