/*************************************************************************
	> File Name: 7.toy.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 16时37分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max_n 1000

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void update(float *weight, int ind, int n) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (weight[temp] < weight[l]) temp = l;
        if (r <= n && weight[temp] < weight[r]) temp = r;
        if (temp == ind) break;
        swap(&weight[ind], &weight[temp]);
        ind = temp;
    }
    return ;
}

void build(float *weight, int num) {
    int ind = num >> 1;
    for (int i = num; i >= 1; i--) update(weight, ind, num);
}

float solve(float *weight, int num) {
    while (num > 1) {
        float a = weight[1];
        swap(&weight[1], &weight[num--]);
        update(weight, 1, num);
        float b = weight[1];
        swap(&weight[1], &weight[num--]);
        update(weight, 1, num);
        float c = pow(a * b * b, 1.0 / 3.0);
        weight[++num] = c;
        build(weight, num);
    }
    return weight[1];
}

int main() {
    int n;
    float weight[max_n + 5];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%f", &weight[i]);
    build(weight, n);
    printf("%f\n", solve(weight, n));
    return 0;
}
