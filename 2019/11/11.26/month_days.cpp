/*************************************************************************
	> File Name: month_days.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时34分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int y, m;
    cin >> y >> m;
    switch ((y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
        case 1:
            if (m == 2) cout << 29;
            else if (m == 1 | m == 3 | m == 5 | m == 7 | m == 8 | m == 10 | m == 12) cout << 31;
            else cout << 30;
            break;
        case 0:
            if (m == 2) cout << 28;
            else if (m == 1 | m == 3 | m == 5 | m == 7 | m == 8 | m == 10 | m == 12) cout << 31;
            else cout << 30;
            break;
    }
    return 0;
}
