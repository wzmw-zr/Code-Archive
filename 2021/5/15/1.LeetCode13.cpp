/*************************************************************************
	> File Name: 1.LeetCode13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 00时02分25秒
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

typedef pair<string, int> PSI;

int romanToInt(string s) {
    vector<PSI> str_val({
        PSI("M", 1000),
        PSI("CM", 900),
        PSI("D", 500),
        PSI("CD", 400),
        PSI("C", 100),
        PSI("XC", 90),
        PSI("L", 50),
        PSI("XL", 40),
        PSI("X", 10),
        PSI("IX", 9),
        PSI("V", 5),
        PSI("IV", 4),
        PSI("I", 1),
    });
    int ans = 0;
    int len = s.size();
    int i = 0;
    for (auto x : str_val) {
        int l = x.first.size();
        while ((i + l <= len) && (s.substr(i, l) == x.first)) {
            ans += x.second;
            i += l;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}
