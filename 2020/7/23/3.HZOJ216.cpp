/*************************************************************************
	> File Name: 3.HZOJ216.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月23日 星期四 18时28分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

typedef pair<string, int> PSI;

int main() {
    #if 0
    vector<string> s;
    string name;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.push_back(name.substr(name.find(".") + 1, name.size()));
    }
    sort(s.begin(), s.end());
    for (auto &x : s) cout << x << endl;
    #endif
    set<PSI> s;
    string name;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.insert(PSI(name.substr(name.find(".") + 1, name.size()), cnt++));
    }
    for (auto &x : s) cout << x.first << endl;
    return 0;
}
