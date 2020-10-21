/*************************************************************************
	> File Name: 1.LeetCode925.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月21日 星期三 07时52分54秒
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

typedef pair<char, int> PCI;

vector<PCI> handle(string &s) {
    char c = s[0];
    int cnt = 0;
    vector<PCI> ret;
    for (int i = 0; s[i]; i++) {
        if (c == s[i]) cnt++;
        else {
            ret.push_back({c, cnt});
            c = s[i];
            cnt = 1;
        }
    }
    ret.push_back({c, cnt});
    return ret;
}

bool isLongPressedName(string name, string typed) {
    if (typed.size() < name.size()) return false;
    vector<PCI> name_t = handle(name);
    vector<PCI> typed_t = handle(typed);
    if (name_t.size() != typed_t.size()) return false;
    for (int i = 0; i < name_t.size(); i++) {
        if (name_t[i].first == typed_t[i].first && name_t[i].second <= typed_t[i].second) continue;
        return false;
    }
    return true;
}

int main() {
    return 0;
}
