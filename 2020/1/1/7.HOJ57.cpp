/*************************************************************************
	> File Name: 7.HOJ57.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月01日 星期三 16时45分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
using namespace std;

int get_digit(int number, int rest, int digits) {
    for (int i = 1; i <= digits - rest; i++) number /= 10; 
    return number % 10;
}

int digit(int n) {
    if (n <= 9) return n;
    int number = 0, num = 1, digits = 1;
    while (n - 9 * num * digits > 0) {
        number += 9 * num;
        n -= 9 * num * digits;
        num *= 10;
        digits++;
    }
    int rest = n % digits;
    number += n / digits;
    if (rest){
        number += 1;
        return get_digit(number, rest, digits);
    } 
    else return number % 10;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << digit(x) * digit(y) * digit(z) << endl;
    return 0;
}
