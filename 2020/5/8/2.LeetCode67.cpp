/*************************************************************************
	> File Name: 2.LeetCode67.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月08日 星期五 21时40分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverse_string(string &s) {
    string tmp = s;
    int len = s.size();
    for (int i = 0; i < len; i++) s[i] = tmp[len - i - 1];
}

void normal(string &s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] >= '2') {
            s[i] -= 2;
            if (i == len - 1) s += "0";
            s[i + 1] += 1;
        }
    }
}

string add(string a, string b) {
    reverse_string(a);
    reverse_string(b);
    for (int i = 0; i < b.size(); i++) a[i] += b[i] - '0';
    return a;
}

string addBinary(string a, string b) {
    string ret;
    if (a.size() > b.size()) ret = add(a, b);
    else ret = add(b, a);
    normal(ret);
    reverse_string(ret);
    return ret;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << addBinary(s1, s2) << endl;
    return 0;
}
