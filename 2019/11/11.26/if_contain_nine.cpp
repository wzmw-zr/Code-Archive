/*************************************************************************
	> File Name: if_contain_nine.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 00时51分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int a;
    cin >> a;
    while (a > 0) {
        if (a % 10 != 9) a /= 10;
        else {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
