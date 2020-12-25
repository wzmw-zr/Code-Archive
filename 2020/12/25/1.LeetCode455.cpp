/*************************************************************************
	> File Name: 1.LeetCode455.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月25日 星期五 08时13分11秒
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

int findContentChildren(vector<int>& g, vector<int>& s) {
    priority_queue<int, vector<int>, greater<int>> child, cookie;
    for (int x : g) child.push(x);
    for (int x : s) cookie.push(x);
    int ans = 0;
    while (child.size() && cookie.size()) {
        while (cookie.size() && cookie.top() < child.top()) cookie.pop();
        if (cookie.size()) {
            child.pop();
            cookie.pop();
            ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
