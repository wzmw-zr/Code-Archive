/*************************************************************************
	> File Name: 2.suffix_array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月24日 星期四 08时02分28秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> sa(n << 1 + 5, 0);
    vector<int> old_rk(n << 1 + 5, 0);
    vector<int> rk(n << 1 + 5, 0);
    for (int i = 1; s[i]; i++) {
        sa[i] = i;
        rk[i] = s[i];
    }
    for (int w = 1; w < n; w <<= 1) {
        sort(sa.begin() + 1, sa.end(), [&](int a, int b){ return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b]; });
        old_rk = rk;
        for (int p = 0, i = 1; i <= n; i++) {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] && old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
    return 0;
}
