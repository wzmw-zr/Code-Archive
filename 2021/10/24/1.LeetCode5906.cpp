/*************************************************************************
	> File Name: 1.LeetCode5906.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月24日 星期日 10时31分18秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int check(string &s) {
    int n = s.size();
    int h_cnt = 0, h_pos;
    int p_cnt = 0, p_pos;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') return 0;
        if (s[i] == '-') h_cnt++, h_pos = i;
        if (s[i] == '!' || s[i] == ',' || s[i] == '.') p_cnt++, p_pos = i;
    }
    if (h_cnt > 1 || p_cnt > 1) return 0;
    if (h_cnt == 1) {
        if (h_pos == 0 || h_pos == n - 1) return 0;
        if (!(s[h_pos - 1] >= 'a' && s[h_pos - 1] <= 'z' && s[h_pos + 1] >= 'a' && s[h_pos + 1] <= 'z')) return 0;
    }
    if (p_cnt == 1 && (p_pos != n - 1)) return 0;
    return 1;
}

int countValidWords(string sentence) {
    int wzmw_zr_q1 = 0;
    int ind = 0;
    int ans = 0;
    while (sentence[ind]) {
        while (sentence[ind] && sentence[ind] == ' ') ind++;
        if (!sentence[ind]) break;
        string s = "";
        while (sentence[ind] && sentence[ind] != ' ') s += sentence[ind++];
        cout << s << endl;
        ans += check(s);
    }
    return ans;
}

int main() {
    string sentence;
    getline(cin, sentence);
    cout << countValidWords(sentence) << endl;
    return 0;
}
