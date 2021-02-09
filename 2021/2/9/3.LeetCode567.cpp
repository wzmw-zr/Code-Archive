/*************************************************************************
	> File Name: 3.LeetCode567.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月09日 星期二 09时10分06秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

bool checkInclusion(string s1, string s2) {
    int len_1 = s1.size(), len_2 = s2.size();
    if (len_1 > len_2) return false;
    int cnt_1[26];
    int cnt_2[26];
    memset(cnt_1, 0, sizeof(cnt_1));
    memset(cnt_2, 0, sizeof(cnt_2));
    for (int i = 0; s1[i]; i++) cnt_1[s1[i] - 'a']++;
    for (int i = 0; i < len_1 - 1; i++) cnt_2[s2[i] - 'a']++;
    for (int i = len_1 - 1; i < len_2; i++) {
        cnt_2[s2[i] - 'a']++;
        int flag = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt_1[j] == cnt_2[j]) continue;
            flag = 1;
            break;
        }
        if (!flag) return true;
        cnt_2[s2[i - len_1 + 1] - 'a']--;
    }
    return false;
}

int main() {
    return 0;
}
