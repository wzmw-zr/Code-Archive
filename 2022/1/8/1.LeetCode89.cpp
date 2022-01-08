/*************************************************************************
	> File Name: 1.LeetCode89.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月08日 星期六 08时57分14秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<int> grayCode(int n) {
    int ind = 1;
    vector<int> ans = {0, 1};
    while (ind < n) {
        int m = ans.size();
        for (int i = m - 1; i >= 0; i--) ans.push_back((1 << ind) + ans[i]);
        ind++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    auto ans = grayCode(n);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
