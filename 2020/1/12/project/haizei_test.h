/*************************************************************************
	> File Name: haizei_test.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月12日 星期日 18时26分07秒
 ************************************************************************/

#ifndef _HAIZEI_TEST_H
#define _HAIZEI_TEST_H
#define max_n 1000

typedef void (*Func_t)();
extern Func_t func_arr[max_n];
extern int cnt;

#define Func_name(a, b) a##__haizei__##b
#define Name(a, b) #a "__haizei__" #b

#define TEST(a, b) \
    void a##__haizei__##b();\
    __attribute__((constructor))\
    void add_##a##__haizei__##b() {\
        func_arr[cnt++] = a##__haizei__##b;\
    }\
    void a##__haizei__##b()


#define EXPECT_EQ(a, b) ({\
    printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" :"False");\
})

int RUN_ALL_TESTS();
#endif
