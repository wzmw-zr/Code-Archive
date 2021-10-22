/*************************************************************************
	> File Name: 1.LeetCode229.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月22日 星期五 12时28分55秒
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

vector<int> majorityElement(vector<int>& nums) {
    vector<int> check(2, INT32_MIN);
    vector<int> cnt(2, 0);
    int n = nums.size();
    for (int x : nums) {
        if (check[0] == x) cnt[0]++;
        else if (check[1] == x) cnt[1]++;
        else {
            if (!cnt[0]) check[0] = x, cnt[0] = 1;
            else if (!cnt[1]) check[1] = x, cnt[1] = 1;
            else cnt[0]--, cnt[1]--;
        }
    }
    cnt[0] = cnt[1] = 0;
    for (int x : nums) {
        if (x == check[0]) cnt[0]++;
        if (x == check[1]) cnt[1]++;
    }
    vector<int> ans;
    if (cnt[0] > n / 3) ans.push_back(check[0]);
    if (cnt[1] > n / 3) ans.push_back(check[1]);
    return ans;
}

int main() {
    return 0;
}
