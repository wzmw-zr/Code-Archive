/*************************************************************************
	> File Name: 6.LeetCode1496.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月04日 星期三 22时20分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

bool isPathCrossing(string path) {
    unordered_map<char, PII> mp;
    set<PII> st;
    mp['N'] = {0, 1}, mp['S'] = {0, -1}, mp['W'] = {-1, 0}, mp['E'] = {1, 0};
    PII p(0, 0);
    st.insert(p);
    for (int i = 0; path[i]; i++) {
        p.first += mp[path[i]].first;
        p.second += mp[path[i]].second;
        if (st.count(p)) return true;
        st.insert(p);
    }
    return false;
}

int main() {
    string path;
    cin >> path;
    cout << (isPathCrossing(path) ? "true" : "false") << endl;
    return 0;
}
