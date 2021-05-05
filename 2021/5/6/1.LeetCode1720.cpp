/*************************************************************************
	> File Name: 1.LeetCode1720.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月06日 星期四 00时02分54秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> ans;
    ans.push_back(first);
    for (int x : encoded) {
        first ^= x;
        ans.push_back(first);
    }
    return ans;
}

int main() {
    return 0;
}
