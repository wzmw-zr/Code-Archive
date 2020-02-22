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

typedef struct Function {
    Func_t func_name;
    const char *str;
    Function *next;
} Function;

typedef struct Function_Info {
    int total, success;
} function_info;

extern function_info info;
extern Function head, *tail;

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m" 
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a,31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define Func_name(a, b) a##__haizei__##b
#define Name(a, b) #a "." #b

#define TEST(a, b) \
    void Func_name(a, b)();\
    __attribute__((constructor))\
    void add_##a##__haizei__##b() {\
        add_function(Func_name(a, b), Name(a, b));\
    }\
    void Func_name(a, b)() 

#define TYPE(a) _Generic((a),\
    int: "%d",\
    double: "%lf",\
    float: "%f",\
    long: "%lld",\
    char *: "%s"\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, cmp) ({\
    printf(GREEN("[-----------] ") #a " " #cmp " " #b);\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    printf(" %s\n", __a cmp __b ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
    info.total += 1;\
    if (__a cmp __b) info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect " #a " " #cmp " " #b " actual : "));\
        P(__a, YELLOW_HL); \
        P(" vs ", YELLOW_HL);\
        P(__b, YELLOW_HL); \
        printf("\n");\
        printf("\n");\
    }\
})
#define EXPECT_EQ(a, b) EXPECT(a, b, ==) 
#define EXPECT_LT(a, b) EXPECT(a, b, <) 
#define EXPECT_GT(a, b) EXPECT(a, b, >) 
#define EXPECT_LE(a, b) EXPECT(a, b, <=) 
#define EXPECT_GE(a, b) EXPECT(a, b, >=) 

int RUN_ALL_TESTS();
void add_function(Func_t func, const char *str);
#endif
