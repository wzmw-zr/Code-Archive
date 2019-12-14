/*************************************************************************
	> File Name: 1.log.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 19时17分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define DEBUG

#ifdef DEBUG
#define log(frm, arg...) {\
    printf("[%s : %s : %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##arg);\
    printf("\n");\
}
#else
#define log(frm, arg...)
#define contact(a, b) a##b

#endif
int main () {
    int a = 123;
    int abcdef = 15;
    log("%d", a);
    //contact(abc, def) = 23;
    printf("%d", abcdef);
    return 0;
}
