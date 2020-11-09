#include <stdio.h>
#define pi 3.14

int main () {
    float r, h;
    scanf("%f%f", &r, &h);
    printf("%.2f\n", r * r * pi);
    printf("%.2f", r * r * pi * h);
    return 0;
}
