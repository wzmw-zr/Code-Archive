/*************************************************************************
	> File Name: 1.LeetCode888.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月01日 星期一 00时01分40秒
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

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum_a = 0, sum_b = 0;
    unordered_set<int> st;
    for (int &x : A) {
        sum_a += x;
        st.insert(x);
    }
    for (int &x : B) sum_b += x;
    vector<int> ans(2, 0);
    int dis = (sum_a - sum_b) / 2;
    for (int &x : B) {
        if (!st.count(x + dis)) continue;
        ans[0] = x + dis;
        ans[1] = x;
        break;
    }
    return ans;
}

int main() {
    return 0;
}
