/*************************************************************************
	> File Name: minium_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 19时04分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    cin >> n;
    int result, temp;
    cin >> result;
    for (int i = 1; i <= n - 1; i++) {
        cin >> temp;
        if (temp < result) result = temp;
    }
    cout << result;
    return 0;
}
