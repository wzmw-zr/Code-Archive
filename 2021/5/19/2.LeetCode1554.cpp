/*************************************************************************
	> File Name: 2.LeetCode1554.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月19日 星期三 00时31分20秒
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

bool differByOne(vector<string>& dict) {
    int n = dict.size();
    int m = dict[0].size();
    for (int i = 0; i < m; i++) {
        unordered_set<string> st;
        for (int j = 0; j < n; j++) {
            char c = dict[j][i];
            dict[j][i] = 'a';
            if (st.count(dict[j])) return true;
            st.insert(dict[j]);
            dict[j][i] = c;
        }
    }
    return false;
}

int main() {
    return 0;
}
