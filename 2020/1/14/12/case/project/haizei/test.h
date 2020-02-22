/*************************************************************************
	> File Name: test.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月12日 星期日 10时29分40秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b) void a##__haizei__##b()
#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "true" : "false");

int RUN_ALL_TESTS();

#endif
