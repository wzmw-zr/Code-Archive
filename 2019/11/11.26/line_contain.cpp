/*************************************************************************
	> File Name: line_contain.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 00时33分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a <= c && b >= d) || (c <= a && d >= b)) cout << "YES";
    else cout << "NO";
    return 0;
}
