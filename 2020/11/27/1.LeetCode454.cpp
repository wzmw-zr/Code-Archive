/*************************************************************************
	> File Name: 1.LeetCode454.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月27日 星期五 07时54分18秒
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

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int x : A) {
        for (int y : B) mp[x + y]++;
    }
    for (int x : C) {
        for (int y : D) {
            if (mp.count((x + y) * -1)) ans += mp[x + y];
        }
    }
    return ans;
}

int main() {
    return 0;
}
