/*************************************************************************
	> File Name: 5.LeetCode1309.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 22时16分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

string freqAlphabets(string s) {
    string ans = "";
    unordered_map<int, char> mp;
    for (int i = 1, j = 'a'; i <= 26; i++, j++) mp[i] = j;
    for (int i = s.size() - 1; i >= 0; ) {
        if (s[i] == '#') {
            ans = mp[stoi(s.substr(i - 2, 2))] + ans;
            i -= 3;
        } else {
            ans = mp[s[i] - '0'] + ans;
            i--;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << freqAlphabets(s) << endl;
    return 0;
}
