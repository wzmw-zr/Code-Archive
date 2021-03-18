/*************************************************************************
	> File Name: 3.LeetCode781.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月18日 星期四 21时55分08秒
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

int numRabbits(vector<int>& answers) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int &x : answers) mp[x]++;
    for (auto &&[num, cnt] : mp) {
        int group = (cnt / (num + 1)) + ((cnt % (num + 1)) ? 1 : 0);
        ans += group * (num + 1);
    }
    return ans;
}

int main() {
    return 0;
}
