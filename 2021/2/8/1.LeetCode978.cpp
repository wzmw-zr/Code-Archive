/*************************************************************************
	> File Name: 1.LeetCode978.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月08日 星期一 00时02分32秒
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

int maxTurbulenceSize(vector<int>& arr) {
    if (arr.size() == 1)  return 1;
    int n = arr.size(), l = 0, r = 1, ans = 1, status = 0;
    if (arr[0] == arr[1]) l = 1, status = 0;
    else if (arr[0] < arr[1]) status = -1;
    else status = 1;
    while (r < n - 1) {
        if (arr[r] == arr[r + 1]) ans = max(ans, r - l + 1), l = r + 1, status = 0;
        else if (arr[r] < arr[r + 1]) {
            if (status == -1) ans = max(ans, r - l + 1), l = r;
            else status = -1;
        } else {
            if (status == 1) ans = max(ans, r - l + 1), l = r;
            else status = 1;
        }
        r++;
    }
    ans = max(ans, r - l + 1);
    return ans;
}

int main() {
    return 0;
}
