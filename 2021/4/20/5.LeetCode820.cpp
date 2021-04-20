/*************************************************************************
	> File Name: 5.LeetCode820.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月20日 星期二 22时22分23秒
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

// WA
int minimumLengthEncoding(vector<string>& words) {
    int ans = 0;
    string concat_word = "";
    for (string s : words) {
        int len_s = s.size(), len_cat_word = concat_word.size();
        if (len_s >= len_cat_word) {
            if (s.substr(len_s - len_cat_word) == concat_word) {
                concat_word = s;
                ans = concat_word.size() + 1;
            } else {
                concat_word += s;
                ans += s.size() + 1;
            }
        } else {
            if (concat_word.substr(len_cat_word - len_s) == s) continue;
            else {
                concat_word += s;
                ans += s.size() + 1;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
