/*************************************************************************
	> File Name: main.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月07日 星期二 09时48分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testFunc, add) {
    EXPECT_EQ(add(5, 3) ,8);
    EXPECT_EQ(add(5, 3), 9);
}

TEST(testFunc, add2) {
    EXPECT_EQ(add(5, 3) ,8);
    EXPECT_EQ(add(5, 3), 9);
}

TEST(testFunc, add3) {
    EXPECT_EQ(add(5, 3) ,8);
    EXPECT_EQ(add(5, 3), 8);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
