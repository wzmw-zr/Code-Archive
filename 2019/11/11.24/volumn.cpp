#include <stdio.h>
#define pi 3.14

int main () {
    //double类型数据的输出格式
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2lf\n", r * r * pi);
    printf("%.2lf", r * r * pi * h);
    return 0;
}
