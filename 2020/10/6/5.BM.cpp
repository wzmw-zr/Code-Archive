/*************************************************************************
	> File Name: 5.BM.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月06日 星期二 20时09分52秒
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
#include<algorithm>
using namespace std;

#define MAX_N 10000
#define MAX_M 1000010

char pattern[MAX_N + 10];
char text[MAX_M + 10];
int bad_char[256];
int suffix[MAX_N + 10];
int temp_suffix[MAX_N + 10];
int good_suffix[MAX_N + 10];
int n, m;
int longest_prefix;

void BadChar() {
    for (int i = 0; i < 256; i++) bad_char[i] = n;
    for (int i = 0; pattern[i]; i++) bad_char[pattern[i]] = n - 1 - i;
}

void GoodSuffix() {
    for (int i = 0; i < n; i++) {
        int len = 0;
        while (i - len >= 0 && pattern[i - len] == pattern[n - 1 - len]) len++;
        if (i - len < 0) longest_prefix = len;
        suffix[i] = len;
    }
    for (int i = 0; i < n; i++) temp_suffix[i] = n;
    for (int i = 0; i < n; i++) temp_suffix[suffix[i]] = n - 1 - i;
    for (int i = 0; i < n; i++) good_suffix[i] = temp_suffix[n - 1 - i];
}

int main() {
    printf("pattern : ");
    fflush(stdout);
    scanf("%s", pattern);
    printf("text : ");
    fflush(stdout);
    scanf("%s", text);
    n = strlen(pattern);
    m = strlen(text);
    BadChar();
    GoodSuffix();
    for (int i = 0; i + n - 1 <= m - 1; ) {
        int j = i + n - 1, match = 0;
        while (match < n && text[j - match] == pattern[n - match]) match++;
        if (match == n) {
            cout << "Match" << endl;
            return 0;
        }
        int bad_char_move = bad_char[text[j - match]] == n ? n : bad_char[text[j - match]] - match;
        int good_suffix_move = good_suffix[j - match];
        i += max(bad_char_move, good_suffix_move);
    }
    cout << "Miss" << endl;
    return 0;
}
