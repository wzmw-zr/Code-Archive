/*************************************************************************
	> File Name: 4.LeetCode541.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 14时32分36秒
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

string reverseStr(string s, int k) {
    int i = 0, n = s.size();
    for (i = 0; i + 2 * k < n; i += 2 * k) {
        int x = i, y = i + k - 1;
        while (x <= y) swap(s[x++], s[y--]);
    }
    if (i + k < n) {
        int x = i, y = i + k - 1;
        while (x <= y) swap(s[x++], s[y--]);
    } else {
        int x = i, y = n - 1;
        while (x <= y) swap(s[x++], s[y--]);
    }
    return s;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << reverseStr(s, n) << endl;
    return 0;
}
