/*************************************************************************
	> File Name: 9.longest.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月22日 星期六 22时51分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

typedef struct UnionSet {
    int *min, *size, n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *) malloc(sizeof(UnionSet));
    u->min = (int *) malloc(sizeof(int) * (n + 1));
    u->size = (int *) malloc(sizeof(int) * (n + 1));
    u->n = 0;
    for (int i = 0; i <= n; i++) {
        u->min[i] = INT32_MIN;
        u->size[i] = 0;
    }
    return u;
}

void output(UnionSet *u) {
    for (int i = 0; i < u->n; i++) {
        if (u->size[i]) printf("u->min[%d] = %d, u->size[%d] = %d\n", i, u->min[i], i, u->size[i]);
    }
}

void insert(UnionSet *u, int num) {
    if (!u->n) {
        printf("new data %d\n", num);
        u->min[0] = num;
        u->size[0] = 1;
        u->n++;
        output(u);
        return ;
    }
    int i = 0, ind1, ind2, flag1 = 0, flag2 = 0;
    while (i <= u->n) {
        if (u->min[i] == INT32_MIN){
            i++;
            continue;
        } 
        if (u->min[i] <= num && u->min[i] + u->size[i] > num) return ;
        if (u->min[i] == num + 1)  {
            u->min[i] = num;
            flag1 = 1;
            ind1 = i;
            i++;
            continue;
        }
        if (u->min[i] + u->size[i] == num) {
            flag2 = 1;
            ind2 = i;
            i++;
            continue;
        }
        i++;
    }
    printf("flag1 = %d, flag2 = %d\n", flag1, flag2);
    if (flag1 && flag2) {
        u->size[ind2] += u->size[ind1] + 1;
        printf("u->min[%d] = %d, u->size[%d] = %d\n\n", ind1, u->min[ind1], ind1, u->size[ind1]);
        u->min[ind1] = INT32_MIN;
        u->size[ind1] = 0;
    } else if (flag1 && !flag2) {
        u->size[ind1]++;
        printf("u->min[%d] = %d, u->size[%d] = %d\n\n", ind1, u->min[ind1], ind1, u->size[ind1]);
    } else if (!flag1 && flag2) {
        u->size[ind2]++;
        printf("u->min[%d] = %d, u->size[%d] = %d\n\n", ind2, u->min[ind2], ind2, u->size[ind2]);
    } else {
        u->min[u->n] = num;
        u->size[u->n] = 1;
        printf("\nnew data %d\n", num);
        u->n++;
    }
    output(u);
}

void clear(UnionSet *u) {
    if (!u) return ;
    free(u->min);
    free(u->size);
    free(u);
}


int longestConsecutive(int* nums, int numsSize){
    UnionSet *u = init(numsSize);
    for (int i = 0; i < numsSize; i++) {
        insert(u, nums[i]);
        printf("%d is the %d number to insert\n", nums[i], i);
    }
    int max_l = 0;
    for (int i = 0; i < u->n; i++) if (u->size[i] > max_l) max_l = u->size[i];
    output(u);
    clear(u);
    return max_l;
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i< n; i++) scanf("%d", &num[i]);
    printf("result = %d\n", longestConsecutive(num, n));
    return 0;
}
