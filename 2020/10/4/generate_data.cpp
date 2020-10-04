/*************************************************************************
	> File Name: generate_data.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 14时29分11秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

#define MAX_N 100000
char s[MAX_N + 10];

int main() {
    srand(time(0));
    for (int i = 0; i < MAX_N; i++) {
        s[i] = rand() % 26 + 'a';
    }
    printf("%s\n", s);
    return 0;
}
