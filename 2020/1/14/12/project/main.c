/*************************************************************************
	> File Name: main.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月14日 星期二 16时46分41秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include "haizei_test.h"
#include "unit.h"


TEST(test1, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_LT(add(0, 0), 0);
    EXPECT_GT(add(-1, -7), -8);
}


TEST(test2, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_LT(add(0, 0), 0);
    EXPECT_GT(add(-1, -7), -8);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}

