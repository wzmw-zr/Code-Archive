/*************************************************************************
	> File Name: 2.LeetCode316.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月20日 星期日 08时53分51秒
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

string removeDuplicateLetters(string s) {
    unordered_map<char, int> cnt;
    unordered_map<char, bool> check;
    for (char c : s) cnt[c]++;
    for (auto &&[c, n] : cnt) check[c] = false;
    stack<char> st;
    for (int i = 0; s[i]; i++) {
        cnt[s[i]]--;
        if (check[s[i]]) continue;
        while (!st.empty() && st.top() > s[i] && cnt[st.top()]) {
            check[st.top()] = false;
            st.pop();
        }
        st.push(s[i]);
        check[s[i]] = true;
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << removeDuplicateLetters(s) << endl;
    return 0;
}
