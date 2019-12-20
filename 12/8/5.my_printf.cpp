/*************************************************************************
	> File Name: 5.my_printf.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时44分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int reverse_number(int num, int *temp) {
    int digit = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        digit++;
    } while (num);
    return digit;
}

int output_num(int temp, int digit) {
    int cnt = 0;
    while (digit) {
        putchar(temp % 10 + '0');
        temp /= 10;
        cnt++;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int count = 0;
    #define PUTC(a) putchar(a), ++count
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case 'd': {
                        int xx = va_arg(arg, int), temp = 0, digit = 0;
                        uint32_t x;
                        if (xx < 0) PUTC('-'), x = -xx;
                        else x = xx;
                        int num1 = x / 100000,  num2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_number(num1, &temp1);
                        int digit2 = reverse_number(num2, &temp2);
                        if (num1) digit = 5;
                        else digit = 0;
                        count += output_num(temp1, digit1);
                        count += output_num(temp2, digit2);
                    } break;
                    case '%': {
                        PUTC(frm[i]);
                    } break;
                    case 's':{
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            putchar(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]);
        }
    }
    #undef PUTC
    va_end(arg);
    return count; 
}


int main () {
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int(a) = %d\n", a);
    my_printf("int (a) = %d\n", a);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);
    char s[100] = "I love Beijing";
    printf("%s\n", s);
    my_printf("%s\n", s);
    return 0;
}
