/*************************************************************************
	> File Name: 3.LeetCode370.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月17日 星期三 23时22分46秒
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

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans(length + 1, 0);
    for (auto &x : updates) {
        ans[x[0]] += x[2];
        ans[x[1] + 1] -= x[2];
    }
    for (int i = 0; i < length; i++) ans[i + 1] += ans[i];
    ans.pop_back();
    return ans;
}

int main() {
    return 0;
}
