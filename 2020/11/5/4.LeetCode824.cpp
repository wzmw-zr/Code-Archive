/*************************************************************************
	> File Name: 4.LeetCode824.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 22时04分25秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

inline bool check(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string toGoatLatin(string S) {
    istringstream ss(S);
    string str, suf = "a";
    string ans = "";
    while (ss >> str) {
        if (check(str[0])) str += "ma" + suf;
        else {
            str += str[0];
            str.erase(str.begin());
            str += "ma" + suf;
        }
        suf += "a";
        ans += str + " ";
    }
    ans.erase(ans.end() - 1);
    return ans;
}

int main() {
    string S;
    getline(cin, S);
    cout << toGoatLatin(S) << endl;
    return 0;
}
