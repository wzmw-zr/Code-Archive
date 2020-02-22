/*************************************************************************
	> File Name: main.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月12日 星期日 10时25分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<haizei/test.h>
using namespace std;

int add(int a, int b) {
    return a + b;
}

TEST(testFunc, add) {
    EXPECT_EQ(add(3, 5), 8);
    EXPECT_EQ(add(3, 5), 9);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
