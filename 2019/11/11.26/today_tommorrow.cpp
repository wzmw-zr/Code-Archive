/*************************************************************************
	> File Name: today_tommorrow.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 22时37分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int y, m, d;
    cin >> y >> m >> d;
    if (y % 4 == 0) {
        if ((y % 100 == 0 && y % 400 ==0) || y % 100 != 0) {
            switch (m) {
                case 1 : 
                if (d == 1) {
                    cout << y - 1 << " " << 12 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 2 : 
                if (d == 1) {
                    cout << y << " " << 1 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 29) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 3:
                if (d == 1) {
                    cout << y << " " << m -1 << " " << 29 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 4:
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 30) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 5 :
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 30 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 6 :
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 30) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 7:
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 30 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 8:
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 9 :
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 30) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 10:
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 30 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 11 :
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 31 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 30) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y << " " << m + 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
                case 12 :    
                if (d == 1) {
                    cout << y << " " << m - 1 << " " << 30 << endl;
                    cout << y << " " << m << " " << 2 << endl;
                }else if (d == 31) {
                    cout << y << " " << m << " " << d - 1 << endl; 
                    cout << y + 1 << " " << 1 << " " << 1 << endl;
                }else {
                    cout << y << " " << m << " " << d - 1 << endl;
                    cout << y << " " << m << " " << d + 1 << endl; 
                }
                break;
            }
            return 0; 
        }
    }
    switch (m) {
    case 1 : 
    if (d == 1) {
        cout << y - 1 << " " << 12 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 2 : 
    if (d == 1) {
        cout << y << " " << 1 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 28) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 3:
    if (d == 1) {
        cout << y << " " << m -1 << " " << 28 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 4:
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 30) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 5 :
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 30 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 6 :
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 30) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 7:
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 30 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 8:
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 9 :
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 30) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 10:
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 30 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 11 :
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 31 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 30) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y << " " << m + 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
    case 12 :    
    if (d == 1) {
        cout << y << " " << m - 1 << " " << 30 << endl;
        cout << y << " " << m << " " << 2 << endl;
    }else if (d == 31) {
        cout << y << " " << m << " " << d - 1 << endl; 
        cout << y + 1 << " " << 1 << " " << 1 << endl;
    }else {
        cout << y << " " << m << " " << d - 1 << endl;
        cout << y << " " << m << " " << d + 1 << endl; 
    }
    break;
}
    return 0;
}
