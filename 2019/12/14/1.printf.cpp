/*************************************************************************
	> File Name: 1.printf.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 08时37分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


#define PUTC(a) putchar(a), count++


int my_printf(const char *fmt, ...) {
    int count = 0;
    va_list arg;
    va_start(arg, fmt);
   // 注意字面量传参数时，需要使用字符串常量来接受 
    for (int i = 0; fmt[i]; i++) {
        switch (fmt[i]) {
            case '%' : {
                switch (fmt[++i]) {
                    case 'd' :  {
                        int x = va_arg(arg, int), temp = 0, digit = 0;
                        if (x < 0) PUTC('-'), x = -x;
                        do {
                            temp = temp * 10 + x % 10;
                            x /= 10;
                            digit++;
                        } while (x);

                        while (digit--) {
                            PUTC(temp % 10 + '0');
                            temp /= 10;
                        }
                    } break;

                    case '%' : {
                        PUTC(fmt[i]);
                    } break;

                    case 'c' : {
                        
                    } break;

                    case 's' : {

                    } break;
                }
            } break;

            default : PUTC(fmt[i]); break;
        }
    }
    return count;
}

int main () {
    
    return 0;
}
