/*************************************************************************
	> File Name: hire.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 00时36分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((b <= 50 || a >= 1) && (c <= 25 || d >=5)) cout << "ok";
    else cout << "pass";
    return 0;
}
