/*************************************************************************
	> File Name: 5.manacher.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 13时38分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

vector<int> manacher(string s) {
    string str = "#";
    for (int i = 0; s[i]; i++) str += s[i], str += "#";
    str += "#";
    int n = str.size();
    vector<int> ans(n, 1);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        ans[i] = i > r ? 1 : min(r - i + 1, ans[l + r - i]);
        while (i - ans[i] >= 0 && i + ans[i] < n && s[i - ans[i]] == s[i + ans[i]]) ans[i]++;
        if (i + ans[i] - 1 > r) l = i - ans[i] + 1, r = i + ans[i] - 1;
    }
    for (int i = 0; i < n; i++) ans[i] -= 1;
    return ans;
}

int main() {
    return 0;
}
