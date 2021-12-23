/*************************************************************************
	> File Name: 2.LeetCode1044.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月23日 星期四 16时46分38秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ctime>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long a1, a2, mod1, mod2;

using PLL = pair<long, long>;

long q_pow(long a, long len, long mod) {
    long ans = 1, p = a;
    while (len) {
        if (len & 1) ans = (ans * p) % mod;
        p = (p * p) % mod;
        len >>= 1;
    }
    return ans;
}

int check(string &s, int len) {
    int n = s.size();
    long p1 = q_pow(a1, len, mod1);
    long p2 = q_pow(a2, len, mod2);
    set<PLL> st;
    long h1 = 0, h2 = 0;
    for (int i = 0; i < len; i++) {
        h1 = (h1 * a1 + static_cast<long>(s[i] - 'a')) % mod1;
        h2 = (h2 * a2 + static_cast<long>(s[i] - 'a')) % mod2;
    }
    st.insert(PLL(h1, h2));
    cout << "h1 = " << h1 << ", h2 = " << h2 << endl;
    for (int i = len; i < n; i++) {
        h1 = (h1 * a1 - static_cast<long>(s[i - len] - 'a') * p1 + static_cast<long>(s[i] - 'a')) % mod1;
        h2 = (h2 * a2 - static_cast<long>(s[i - len] - 'a') * p2 + static_cast<long>(s[i] - 'a')) % mod2;
        if (h1 < 0) h1 = (h1 + mod1) % mod1;
        if (h2 < 0) h2 = (h2 + mod2) % mod2;
        cout << "h1 = " << h1 << ", h2 = " << h2 << endl;
        PLL temp(h1, h2);
        if (st.count(temp)) return i - len + 1;
        st.insert(temp);
    }
    return -1;
}

string longestDupSubstring(string s) {
    srand(time(0));
    int n = s.size();
    int l = 1, r = n - 1;
    int start_idx = -1, len = 0;
    a1 = (rand() % 75) + 26;
    a2 = (rand() % 75) + 26;
    mod1 = (rand() % 1000000006) + 1000000006;
    mod2 = (rand() % 1000000006) + 1000000006;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        cout << "mid = " << mid << endl;
        int idx = check(s, mid);
        if (idx != -1 && mid > len) start_idx = idx, len = mid;
        if (idx != -1) l = mid;
        else r = mid - 1;
    }
    int idx = check(s, l);
    if (idx != -1 && l > len) start_idx = idx, len = l;
    return start_idx == -1 ? "" : s.substr(start_idx, len);
}

int main() {
    return 0;
}
