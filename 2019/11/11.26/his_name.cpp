/*************************************************************************
	> File Name: his_name.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时47分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    char c;
    cin >> c;
    switch(c) {
        case 'h': cout << "He"; break;
        case 'l': cout << "Li"; break;
        case 'c': cout << "Cao"; break;
        case 'd': cout << "Duan"; break;
        case 'w': cout << "Wang"; break;
        default: cout << "Not Here"; break;
    }
    return 0;
}
