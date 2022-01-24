/*************************************************************************
	> File Name: 2.LeetCode2139.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月24日 星期一 10时57分28秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using TIII = tuple<int, int, int>;

int minMoves(int target, int maxDoubles) {
    int ans = 0;
    while (target != 1) {
        if (!(target & 1) && maxDoubles) {
            target /= 2;
            maxDoubles--;
            ans++;
        } else if (!maxDoubles) {
            ans += target - 1;
            target = 1;
        } else {
            target--;
            ans++;
        }
    }
    return ans;
}

int main() {
    int target;
    int maxDoubles;
    cin >> target >> maxDoubles;
    cout << minMoves(target, maxDoubles) << endl;
    return 0;
}
