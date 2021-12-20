/*************************************************************************
	> File Name: 1.LeetCoded475.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月20日 星期一 09时31分19秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int find_last_lesser(int x, vector<int> &heaters) {
    int l = 0, r = heaters.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (heaters[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

int find_first_greater(int x, vector<int> &heaters) {
    int l = 0, r = heaters.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (heaters[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int ans = INT32_MIN;
    for (int x : houses) {
        int l = find_last_lesser(x, heaters);
        int r = find_first_greater(x, heaters);
        ans = max(ans, min(abs(heaters[l] - x), abs(heaters[r] - x)));
    }
    return ans;
}

int main() {
    return 0;
}
