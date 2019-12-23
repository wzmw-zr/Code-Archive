/*************************************************************************
	> File Name: 5.fraction.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 18时02分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;


int is_val(int i, int j) {
    int i_1 = i % 10, i_2 = i / 10, j_1 = j % 10, j_2 = j / 10;
    if (i_1 == 0 && j_1 == 0) return 0;
    if (i_1 == j_1 && i_2 * j == j_2 * i) return 1;
    if (i_1 == j_2 && i_2 * j == j_1 * i) return 1;
    if (i_2 == j_1 && i_1 * j == j_2 * i) return 1;
    if (i_2 == j_2 && i_1 * j == j_1 * i) return 1;
    return 0;
}


int gcd(int i, int j) {
    if (j == 0) return i;
    return gcd(j, i % j);
}


int main() {
    int x = 1, y = 1;
    for (int i = 10; i <= 98; i++) {
        for (int j = i + 1; j <= 99; j++) {
            if (is_val(i, j)) {
                x *= i, y *= j;
            }
        }
    }
    printf("%d\n", y / gcd (x, y));
    return 0;
}
