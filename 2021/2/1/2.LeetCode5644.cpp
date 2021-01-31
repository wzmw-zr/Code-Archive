/*************************************************************************
	> File Name: 2.LeetCode5644.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月01日 星期一 00时12分09秒
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

int handle(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> mp;
    for (int i = lowLimit; i <= highLimit; i++) mp[handle(i)]++;
    int ans = 0;
    for (auto &&[x, cnt] : mp) ans = max(ans, cnt);
    return ans;
}

int main() {
    return 0;
}
