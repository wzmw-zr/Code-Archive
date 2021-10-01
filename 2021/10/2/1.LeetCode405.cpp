/*************************************************************************
	> File Name: 1.LeetCode405.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月02日 星期六 00时03分43秒
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
using namespace std;

string toHex(int num) {
    char mp[16];
    for (int i = 0; i < 10; i++) mp[i] = '0' + i;
    for (int i = 10; i < 16; i++) mp[i] = 'a' + i - 10;
    string ans = "";
    unsigned int t = num;
    do {
        ans = mp[t & 0xf] + ans;
        t >>= 4;
    } while (t);
    return ans;
}

int main() {
    int num;
    cin >> num;
    cout << toHex(num) << endl;
    return 0;
}
