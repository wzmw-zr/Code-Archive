#include <stdio.h>
#include <string.h>

int main () {
    float a, b;
    scanf("%f%f", &a, &b);
    // 保留小数位数用法
    printf("%.2f\n", 2 * (a + b));
    printf("%.2f", a *b);
    return 0;
}