/*************************************************************************
	> File Name: ticket.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 21时47分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main () {
    int x, y;
    cin >> x >> y;
    if (x == y) cout << 100;
    else if (x / 10 == y % 10){
        switch (x % 10 == y / 10) {
            case 1 : cout << 20; break;
            case 0 : cout << 2; break;
        }
    }else if (x % 10 == y / 10 || x % 10 == y % 10 || x / 10 == y / 10) {
        cout << 2;
    }else cout << 0;
    return 0;
}
