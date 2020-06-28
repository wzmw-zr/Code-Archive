/*************************************************************************
	> File Name: 1.LeetCode464.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月28日 星期日 08时56分12秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

bool judge(int maxChoosableInteger, int check, int desiredTotal, unordered_map<int, int> &mp) {
    if (mp.find(check) != mp.end()) return mp[check];
    for (int i = maxChoosableInteger; i >= 1; i--) {
        cout << check << endl;
        if (check & (1 << i)) continue;
        if (desiredTotal <= i || !judge(maxChoosableInteger, check | (1 << i), desiredTotal - i, mp)) {
            mp[check] = 1; 
            return true;
        }
    }
    mp[check] = 0;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger >= desiredTotal) return true;
    if (desiredTotal > maxChoosableInteger * (maxChoosableInteger + 1) / 2) return false;
    int check = 0;
    unordered_map<int, int> mp;
    return judge(maxChoosableInteger, check, desiredTotal, mp);
}

int main() {
    int maxChoosableInteger, desiredTotal;
    cin >> maxChoosableInteger >> desiredTotal;
    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "Yes" : "No") << endl;
    return 0;
}
