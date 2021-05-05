/*************************************************************************
	> File Name: 3.LeetCode984.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月05日 星期三 23时10分04秒
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
string strWithout3a3b(int a, int b) {
    int x, y;
    string ans = "";
    if (a >= b) {
        x = a - b;
        y = b - x;
        cout << x << " " << y << endl;
        for (int i = 0; i < x; i++) ans += "aab";
        for (int i = 0; i < y; i++) ans += "ab";
    } else {
        x = b - a;
        y = a - x;
        cout << x << " " << y << endl;
        for (int i = 0; i < x; i++) ans += "bba";
        for (int i = 0; i < y; i++) ans += "ba";
    }
    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << strWithout3a3b(a, b) << endl;
    return 0;
}
