/*************************************************************************
	> File Name: 1.LeetCode399.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月18日 星期五 08时12分18秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
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

char findTheDifference(string s, string t) {
    int mp[26];
    memset(mp, 0, sizeof(mp));
    for (char c : s) mp[c - 'a']++;
    for (char c : t) mp[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (!mp[i]) continue;
        return i + 'a';
    }
    return 'a';
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << findTheDifference(s, t) << endl;
    return 0;
}
