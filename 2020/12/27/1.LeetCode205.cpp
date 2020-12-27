/*************************************************************************
	> File Name: 1.LeetCode205.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月27日 星期日 08时40分05秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

bool isIsomorphic(string s, string t) {
    char mp_s[256], mp_t[256];
    memset(mp_s, 0, sizeof(mp_s));
    memset(mp_t, 0, sizeof(mp_t)); 
    for (int i = 0; s[i]; i++) {
        if (!mp_s[s[i]] && mp_t[t[i]]) return false;
        if (mp_s[s[i]] && !mp_t[t[i]]) return false;
        if (mp_s[s[i]] && mp_t[t[i]]) {
            if ((s[i] != mp_t[t[i]]) || (t[i] != mp_s[s[i]])) return false;
            continue;
        }
        mp_s[s[i]] = t[i];
        mp_t[t[i]] = s[i];
    }
    return true;
}

int main() {
    return 0;
}
