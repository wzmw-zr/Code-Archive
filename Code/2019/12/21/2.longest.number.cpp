/*************************************************************************
	> File Name: 2.longest.number.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 09时50分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000000
#define max_length 1000000
using namespace std;

int length[max_length + 5] = {0};


int64_t get_len(int64_t x) {
    if (x == 1) return 1;
    if (x < max_length && length[x]) return length[x];
    int64_t ret;
    if (x & 1) ret = get_len(3 * x + 1) + 1;
    else ret = get_len(x >> 1) + 1;
    if (x < max_length) length[x] = ret;
    return ret;
}

int main() {
    int64_t ans = 0, num = 0;
    for (int64_t i = 1; i < max_n; i++) {
        int64_t l = get_len(i);
        if (l > ans) ans = l, num = i;
    }
    printf("%" PRId64 " %" PRId64 "\n", ans, num);
    return 0;
}
