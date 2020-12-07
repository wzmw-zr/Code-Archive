/*************************************************************************
	> File Name: case.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月07日 星期一 19时59分20秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;

int main() {
    int n = 0b101001000101;
    printf("%X\n", 1 << 0);
    printf("%X\n", ~(1 << 0));
    printf("%X\n", n);
    printf("%X\n", (n & (~(1 << 7))));
    printf("%X\n", (n ^ (1 << 7)));
    //cout << (n & ~(1 << 5)) << " " << (n ^ (1 << 5)) << endl;
    return 0;
}
