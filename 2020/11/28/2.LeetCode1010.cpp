/*************************************************************************
	> File Name: 2.LeetCode1010.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月28日 星期六 08时20分32秒
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

int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int x : time) {
        int temp = (60 - x % 60) % 60;
        if (mp.count(temp)) ans += mp[temp];
        mp[x % 60]++;
    }
    return ans;
}

int main() {
    return 0;
}
