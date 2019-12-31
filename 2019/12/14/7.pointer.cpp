/*************************************************************************
	> File Name: 7.pointer.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 20时31分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Data {
    double a;
    int b;
    char c;
};

#define offset(T, a) ({ \
    T temp; \
    (char *)&temp.a - (char *)&temp;\
})

#define offset1(T, a) (long)(&((T *)(NULL))->a)


int main () {
    int num1=  0x616263;
    int num2=  0x61626364;
    printf("%s\n", (char *) (&num1));
    printf("%s\n", (char *) (&num2));
    printf("%s\n", (char *) (&num2 + 1));
    printf("%ld\n",offset(struct Data, a));
    printf("%ld\n",offset(struct Data, b));
    printf("%ld\n",offset(struct Data, c));
    printf("%ld\n",offset1(struct Data, a));
    printf("%ld\n",offset1(struct Data, b));
    printf("%ld\n",offset1(struct Data, c));
    return 0;
}
