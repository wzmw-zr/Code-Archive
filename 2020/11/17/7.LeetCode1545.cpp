/*************************************************************************
	> File Name: 7.LeetCode1545.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月17日 星期二 11时04分22秒
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

string invert(string s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    return s;
}

string reversed(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) swap(s[i], s[j]);
    return s;
}

char findKthBit(int n, int k) {
    string s = "0";
    for (int i = 1; i < n; i++) {
        s += "1" + reversed(invert(s));
    }
    return s[k - 1];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << findKthBit(n, k) << endl;
    return 0;
}
