/*************************************************************************
	> File Name: 3.LeetCode904.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月10日 星期三 09时25分50秒
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

int totalFruit(vector<int>& tree) {
    int n = tree.size(), l = 0, r = 0, cnt = 0;
    unordered_map<int, int> type;
    while (r < n) {
        type[tree[r]]++;
        while (type.size() > 2) {
            if (!(--type[tree[l++]])) type.erase(type.find(tree[l - 1]));
        }
        cnt = max(cnt, r - l + 1);
        r++;
    }
    return cnt;
}

int main() {
    return 0;
}
