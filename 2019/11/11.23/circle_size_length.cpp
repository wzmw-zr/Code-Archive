#include <stdio.h>
#include <string.h>
#define pi 3.14

int main () {
    float r;
    scanf("%f", &r);
    printf("%.2f\n", 2 * r * pi);
    printf("%.2f", r * pi * pi);
    return 0;
}