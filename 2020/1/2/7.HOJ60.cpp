/*************************************************************************
	> File Name: 7.HOJ60.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月02日 星期四 21时27分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#define EPSLON 1e-6
#define sqrt(a) (0)

#define Plog(frm, arg...) { \
    printf("[ %s : %d -> output ] " frm "\n", __func__, __LINE__, ##arg); \
    fflush(stdout); \
}

double newton_sqrt(double n);

void haizei_test() {
    for (int i = 0; i < 1000; i++) {
        double n = rand() % 1000000;
        double x = newton_sqrt(n);
        assert(fabs(x * x - n) < EPSLON);
        Plog("Accept");
    }
    return ;
}

int main() {
    srand(time(0));
    haizei_test();
    return 0;
}

double newton_sqrt(double n) {
    double left = 0, right = n, mid;
    while (fabs(right - left) > EPSLON) {
        mid = (left + right) / 2;
        if (right - left <= EPSLON) return left;
        if (mid * mid == n) return mid;
        else if (mid * mid < n) left = mid;
        else right = mid;
    }
    return left; 
}
