/*************************************************************************
	> File Name: four_digit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时12分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    while (n > 0) {
        if(n % 2 == 0) {
            cout << "YES";
            return 0;
        }
        else n /= 10;
    }
    cout << "NO";
    return 0;
}
