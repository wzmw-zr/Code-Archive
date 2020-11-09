/*************************************************************************
	> File Name: sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 00时34分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    cout << result;
    return 0;
}
