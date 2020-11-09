/*************************************************************************
	> File Name: game.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 23时44分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    char a, b;
    cin >> a >> b;
    switch (a) {
        case 'O':
        if(b == 'O') cout << "TIE";
        else if (b == 'Y') cout << "MING";
        else cout << "LI";
        break;
        case 'Y':
        if (b == 'O') cout << "LI";
        else if (b == 'Y') cout << "TIE";
        else cout << "MING";
        break;
        case 'H':
        if (b == 'O') cout << "MING";
        else if (b == 'Y') cout << "LI";
        else cout << "TIE";
        break;
    }
    return 0;
}
