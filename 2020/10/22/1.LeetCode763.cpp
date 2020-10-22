/*************************************************************************
	> File Name: 1.LeetCode763.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月22日 星期四 07时10分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;

vector<int> partitionLabels(string S) {
    map<char, PII> mp;
    vector<PII> area;
    for (int i = 0; S[i]; i++) {
        if (!mp.count(S[i])) mp[S[i]] = PII(i, i);
        else mp[S[i]].second = i;
    }
    for (auto &x : mp) area.push_back(x.second);
    sort(area.begin(), area.end(), [](PII &a, PII &b){ return a.first == b.first ? a.second < b.second : a.first < b.first; });
    int left = 0, right = area[0].second;
    vector<int> ans;
    for (int i = 1; i < area.size(); i++) {
        if (right > area[i].first) right = max(right, area[i].second);
        else {
            ans.push_back(right - left + 1);
            left = area[i].first;
            right = area[i].second;
        }
    }
    ans.push_back(right - left + 1);
    return ans;
}

int main() {
    string s;
    cin >> s;
    auto ans = partitionLabels(s);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
