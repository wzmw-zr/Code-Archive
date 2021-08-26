/*************************************************************************
	> File Name: 1.LeetCode881.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月26日 星期四 15时41分49秒
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

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size();
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
        if (people[l] + people[r] <= limit) ans++, l++, r--;
        else ans++, r--;
    }
    ans += l == r ? 1 : 0;
    return ans;
}

int main() {
    return 0;
}
