/*************************************************************************
	> File Name: 4.LeetCode5740.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月25日 星期日 11时03分59秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int longestBeautifulSubstring(string word) {
    char ch[5] = {'a', 'e', 'i', 'o', 'u'};
    int ind = 0;
    int l = 0, r = 0;
    int ans = 0;
    int cnt[5] = {0, 0, 0, 0, 0};
    while (word[r]) {
        if (word[r] == ch[ind]) r++, cnt[ind]++;
        else if (ind < 4 && word[r] == ch[ind + 1] && cnt[ind]) {
            r++;
            ind++;
            cnt[ind]++;
        } else {
            if (ind == 4) ans = max(ans, r - l);   
            if (word[r] == 'a') l = r;
            else l = ++r;
            memset(cnt, 0, sizeof(cnt));
            ind = 0;
        }
    }
    if (ind == 4) ans = max(ans, r - l);
    return ans;
}

int main() {
    string word;
    cin >> word;
    cout << longestBeautifulSubstring(word) << endl;
    return 0;
}
