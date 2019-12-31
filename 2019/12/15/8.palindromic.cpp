/*************************************************************************
	> File Name: 8.palindromic.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 20时47分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000


int ten_p(int i) {
    int x = 0, y = i;
    while (i != 0) {
        x = x * 10 + i % 10;
        i /= 10;
    }
    if (x == y) return 1;
    return 0;
}

int two_p(int i) {
    int x = 0, y = i;
    while (i != 0) {
        x = x * 2 + i % 2;
        i /= 2;
    }
    if (x == y) return 1;
    return 0;
}

int main () {
    int sum = 0;
    for (int i = 1; i <= max_n; i++) {
        if (ten_p(i) && two_p(i)) sum += i; 
    }    
    cout << sum;
    return 0;
}
