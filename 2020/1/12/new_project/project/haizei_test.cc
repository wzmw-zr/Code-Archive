#include<haizei_test.h>
#include<stdio.h>

Func_t func_arr[max_n];
int cnt = 0;

int RUN_ALL_TESTS() {
    for (int i = 0; i < cnt; i++) {
        printf("RUN TEST %d\n", i);
        func_arr[i]();
    }
    return 0;
}
