/*************************************************************************
	> File Name: 1.LeetCode1705.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月24日 星期五 08时40分04秒
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
#include <tuple>
using namespace std;

// WA
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using TIII = tuple<int, int, int>;

int eatenApples(vector<int>& apples, vector<int>& days) {
    int n = apples.size();
    vector<TIII> info;
    for (int i = 0; i < n; i++) {
        int mmin = min(apples[i], days[i]);
        info.push_back(TIII(i + days[i], i + 1, mmin));
    }
    sort(info.begin(), info.end());
    int cur = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto &&[last, first, num] = info[i];
        if (cur > last) continue;
        if (cur < first) cur = first;
        int cnt = min(last - cur + 1, num);
        cur += cnt;
        ans += cnt;
    }
    return ans;
}

int main() {
    return 0;
}
