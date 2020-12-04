/*************************************************************************
	> File Name: 3.LeetCode1497.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月04日 星期五 21时01分40秒
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

bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) mp[i] = 0;
    for (int &x : arr) mp[(x % k + k) % k]++;
    if (mp[0] & 1) return false;
    for (int i = 1, j = k - 1; i <= j; i++, j--) {
        if (i == j) {
            if (mp[i] & 1) return false;
            break;
        }
        if (mp[i] != mp[j]) return false;
    }
    return true;
}

int main() {
    return 0;
}
