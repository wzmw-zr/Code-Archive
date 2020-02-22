/*************************************************************************
	> File Name: main.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月12日 星期日 20时32分46秒
 ************************************************************************/

#include<stdio.h>
#include"gtest/gtest.h"

int add(int a, int b) {
    return a + b;
}

TEST(Functest, add_function) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(1, 2), 4);
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(2, 2), 3);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
