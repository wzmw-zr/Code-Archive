/*************************************************************************
	> File Name: 2.LeetCode5702.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月14日 星期日 10时35分49秒
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

int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, int> mp;
    for (auto &edge : edges) {
        if (++mp[edge[0]] > 1)  return edge[0];
        if (++mp[edge[1]] > 1)  return edge[1];
    }
    return 0;
}

int main() {
    return 0;
}
