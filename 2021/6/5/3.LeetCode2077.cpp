/*************************************************************************
	> File Name: 3.LeetCode2077.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月05日 星期六 00时18分56秒
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

vector<string> getValidT9Words(string num, vector<string>& words) {
    vector<char> inds = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
    vector<string> ans;
    unordered_set<string> st;
    st.insert(num);
    for (string word : words) {
        string t = word;
        for (int i = 0; t[i]; i++) t[i] = inds[t[i] - 'a'];
        if (st.count(t)) ans.push_back(word);
    }
    return ans;
}

int main() {
    return 0;
}
