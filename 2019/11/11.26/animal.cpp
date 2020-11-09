/*************************************************************************
	> File Name: animal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 22时29分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int year;
    cin >> year;
    switch (year % 12) {
        case 3 : cout << "pig"; break;
        case 4 : cout << "rat"; break;
        case 5 : cout << "ox"; break;
        case 6 : cout << "tiger"; break;
        case 7 : cout << "rabbit"; break;
        case 8 : cout << "dragon"; break;
        case 9 : cout << "snake"; break;
        case 10 : cout << "horse"; break;
        case 11 : cout << "sheep"; break;
        case 0 : cout << "monkey"; break;
        case 1 : cout << "rooster"; break;
        case 2 : cout << "dog"; break;
    }
    return 0;
}
