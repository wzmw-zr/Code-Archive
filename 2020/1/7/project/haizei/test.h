/*************************************************************************
	> File Name: test.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月07日 星期二 12时55分13秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\e[" #b "m" a "\e[0m"
#define COLOR_HL(a, b) "\e[1;" #b "m" a "\e[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BULE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BULE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TEST(a, b) \
void a##__haizei__##b(); \
__attribute__((constructor)) \
void add##a##__haizei__##b() { \
    add_function(a##__haizei__##b, #a "." #b);\
    } \
void a##__haizei__##b() 

#define EXPECT(a, b, cmp) {\
    __typeof(a) __a = (a), __b = (b);\
    haizei_test_info.total += 1; \
    printf(GREEN("[===========] ") #a " " #cmp " " #b);\
    printf("%s\n", __a cmp __b ? GREEN(" TRUE") : RED(" FALSE"));\
    if (__a cmp __b) haizei_test_info.success += 1;\
    else {\
    printf("\n");\
    printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
    printf(YELLOW_HL("\t\texpect" #a " " #cmp " " #b " actual : "));\
    printf("\n");\
    }\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)


typedef void (*TestFuncT)();

struct Function {
    TestFuncT func;
    const char *str;
};

struct FunctionInfo {
    int total, success;
};


extern struct FunctionInfo haizei_test_info; 

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);


#endif
