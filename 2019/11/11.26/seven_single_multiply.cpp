/*************************************************************************
	> File Name: seven_single_multiply.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时04分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    n % 7 == 0 && n % 2 != 0 ? cout << "YES" : cout << "NO";
    return 0;
}
