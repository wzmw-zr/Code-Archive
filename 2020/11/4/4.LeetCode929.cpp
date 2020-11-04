/*************************************************************************
	> File Name: 4.LeetCode929.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 08时25分51秒
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

string generate(string str) {
    int mid = str.find('@');
    string pre = str.substr(0, mid);
    string suf = str.substr(mid + 1);
    for (int i = 0; i < pre.size(); ) {
        if (pre[i] == '.') pre.erase(i, 1);
        else i++;
    }
    for (int i = 0; i < pre.size(); i++) {
        if (pre[i] == '+') pre.erase(i);
    }
    return pre + "@" + suf;
}

int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for (auto &x : emails) st.insert(generate(x));
    return st.size();
}

int main() {
    return 0;
}
