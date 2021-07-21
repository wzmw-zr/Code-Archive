/*************************************************************************
	> File Name: 3.LeetCode1936.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月22日 星期四 00时36分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int addRungs(vector<int>& rungs, int dist) {
    int n = rungs.size();
    int pre = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (rungs[i] - pre - 1) / dist;
        pre = rungs[i];
    }
    return ans;
}

int main() {
    return 0;
}
