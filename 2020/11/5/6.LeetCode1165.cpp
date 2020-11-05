/*************************************************************************
	> File Name: 6.LeetCode1165.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 22时27分29秒
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

int calculateTime(string keyboard, string word) {
    unordered_map<char, int> mp;
    int ans = 0;
    for (int i = 0; keyboard[i]; i++) mp[keyboard[i]] = i;
    ans += mp[word[0]];
    for (int i = 1; word[i]; i++) ans += abs(mp[word[i]] - mp[word[i - 1]]);
    return ans;
}

int main() {
    string keyboard, word;
    cin >> keyboard >> word;
    cout << calculateTime(keyboard, word) << endl;
    return 0;
}
