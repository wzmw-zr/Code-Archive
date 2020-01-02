/*************************************************************************
	> File Name: 6.HOJ58.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月02日 星期四 20时57分04秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
})

#define Plog(frm, arg...) ({\
    printf("[ %s : %d ] ", __func__, __LINE__);\
    printf(frm, arg);\
    printf("\n");\
})

void haizei_test() {
    int a = 6;
    Plog("%d", MAX(2, 3));
    Plog("%d", 5 + MAX(2, 3));
    Plog("%d", MAX(2, MAX(3, 4)));
    Plog("%d", MAX(2, 3 > 4 ? 3 : 4));
    Plog("%d", MAX(a++, 6));
    Plog("a value = %d", a);
}

int main() {
    haizei_test();
    return 0;
}
