/*************************************************************************
	> File Name: case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月19日 星期日 09时58分41秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#define MAXN 1000000

int main() {
    string s, tmp = "";
    getline(cin, s);
    for (int i = 1; i <= MAXN; i++) {
        tmp += s;
    }
    cout << tmp;
    return 0;
}
