/*************************************************************************
	> File Name: legal_date.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 23时23分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int y, m, d;
    cin >> y >> m >> d;
    switch (m){
    case 1:
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    case 2:
    if (y >= 0) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            if (d >= 1 && d <= 29) cout << "YES";
            else cout << "NO";
        } 
        else{
            if (d >= 1 && d <= 28) cout << "YES";
            else cout << "NO";
        }
    }else cout << "NO";
    break;
    case 3 :
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    case 4 :
    if (y >= 0 && d >= 1 && d <= 30) cout << "YES";
    else cout << "NO";
    break;
    case 5 :
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    case 6 :
    if (y >= 0 && d >= 1 && d <= 30) cout << "YES";
    else cout << "NO";
    break;
    case 7 :
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    case 8 :
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    case 9: 
    if (y >= 0 && d >= 1 && d <= 30) cout << "YES";
    else cout << "NO";
    break;
    case 10:
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    case 11:
    if (y >= 0 && d >= 1 && d <= 30) cout << "YES";
    else cout << "NO";
    break;
    case 12:
    if (y >= 0 && d >= 1 && d <= 31) cout << "YES";
    else cout << "NO";
    break;
    default:
    cout << "NO";
    break;
    }
    return 0;
}
