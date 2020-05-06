/*************************************************************************
	> File Name: 3.HZOJ588.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 18时23分38秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int n;
string s = "1";

string handle() {
    string tmp;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        int cnt = 0;
        while (i < s.size() && c == s[i]) {
            cnt++;
            i++;
        }
        cout << "i = " << i << endl;
        tmp += cnt + '0';
        tmp += c;
        cout << tmp << endl << endl;
    }
    return tmp;
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        s = handle();
    }
    cout << s << endl;
    return 0;
}
