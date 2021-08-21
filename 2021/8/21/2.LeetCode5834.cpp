/*************************************************************************
	> File Name: 2.LeetCode5834.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月21日 星期六 22时31分03秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int minTimeToType(string word) {
    int ans = 0;
    char ch = 'a';
    for (char c : word) {
        int dis = abs(int(ch - c));
        ans += min(dis, 26 - dis) + 1;
        ch = c;
    }
    return ans;
}

int main() {
    string word;
    cin >> word;
    cout << minTimeToType(word) << endl;
    return 0;
}
