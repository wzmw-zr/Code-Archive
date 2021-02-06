/*************************************************************************
	> File Name: 5.LeetCode1027.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 16时15分42秒
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

// WA

int longestArithSeqLength(vector<int>& A) {
    int n = A.size();
    int l = 0, r = 1, dis = A[1] - A[0], ans = 2, len = 1;
    while (r < n) {
        int temp = A[r] - A[r - 1];
        if (temp == dis) len++;
        else {
            ans = max(ans, r - l);
            l = r - 1;
            dis = temp;
            len = 2;
        }
        r++;
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    return 0;
}
