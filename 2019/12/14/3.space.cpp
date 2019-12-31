/*************************************************************************
	> File Name: 3.space.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 18时45分02秒
 ************************************************************************/

struct node1 {
    char a;
    char b;
    int c;
};

struct node2 {
    char a; 
    int b; 
    char c;
};

union node {
    double a;
    char b;
    int c;
};
#include<iostream>
using namespace std;

int main () {
    printf("%d\n", sizeof(node));
    return 0;
}
