/*************************************************************************
	> File Name: 3.func.point.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月10日 星期五 20时01分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

int f1(int n) {
    return n * 2;
}

int f2(int n) {
    return n * n + 3;
}

int f3(int n) {
    return n >> 1;
}

int (*func[3])(int) = {
    f1, f2, f3
};

int main() {
    int arr[100][100];
    int (*p)[100] = arr;
    return 0;
}
