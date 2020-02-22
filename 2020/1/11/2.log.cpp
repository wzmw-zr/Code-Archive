/*************************************************************************
	> File Name: 2.log.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月11日 星期六 16时15分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define log(frm, arg...) ({\
    printf("[%s : %d]", __func__, __func__, __LINE__);\
    printf(frm, ##arg);\
})

int main() {
    log("hello world");
    return 0;
}
